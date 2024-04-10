#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
main(){
    FAST;
    ll T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;
        char d[n][m];
        ll maxy[26], maxx[26], miny[26], minx[26];
        for(ll i =0 ;i<26;i++) maxy[i] = -1, maxx[i] = -1, miny[i] = INF, minx[i] = INF;
        for(ll i =0;i<n;i++){
            for(ll j = 0;j<m;j++){
                char c;
                cin >> c;
                if(c != '.'){
                    maxy[c-'a'] = max(maxy[c-'a'], i);
                    maxx[c-'a'] = max(maxx[c-'a'], j);
                    miny[c-'a'] = min(miny[c-'a'], i);
                    minx[c-'a'] = min(minx[c-'a'], j);
                }
                d[i][j] = c;
            }
        }
        vector<pair<ll, pair<pll, pll>>> res;
        bool broke = false;
        for(ll i = 25;i>=0;i--){
            if(maxy[i] == -1) continue;
            if(miny[i] == maxy[i]){
                bool ok = true;
                for(ll j = minx[i];j<=maxx[i];j++){
                    ok = ok && (d[miny[i]][j]-'a' == i || d[miny[i]][j] == '*');
                }
                if(ok){
                    for(ll j = minx[i];j<=maxx[i];j++) d[miny[i]][j] = '*';
                    res.pb({i, {{minx[i], miny[i]}, {maxx[i], maxy[i]}}});
                }else broke = true;
            }else if(minx[i] == maxx[i]){
                bool ok = true;
                for(ll j = miny[i];j<=maxy[i];j++){
                    ok = ok && (d[j][maxx[i]]-'a' == i || d[j][maxx[i]] == '*');
                }
                if(ok){
                    for(ll j = miny[i];j<=maxy[i];j++) d[j][maxx[i]] = '*';
                    res.pb({i, {{minx[i], miny[i]}, {maxx[i], maxy[i]}}});
                }else broke = true;
            }else broke = true;
        }
        if(!broke){
            reverse(itr(res));
            ll last = -1;
            vector<pair<pll, pll>> realres;
            for(auto i : res){
                for(ll j = last+1;j <=i.x;j++){
                    realres.pb(i.y);
                }
                last = i.x;
            }
            cout << "YES" << endl << realres.size() << endl;
            for(auto i : realres){
                cout << i.x.y+1 << " " << i.x.x+1 << " " << i.y.y+1 << " " << i.y.x+1 << endl;
            }
        }else cout << "NO" << endl;
    }
}