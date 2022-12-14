#include <bits/stdc++.h>
 
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
 
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e6;
const ll inf = 1e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
 
template <typename T> void vout(T s){cout << s << endl;exit(0);}
 
ll sum(vector <ll> p, ll l, ll r){
    return p[r] - (l ? p[l - 1] : 0);
}
 
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
 
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
 
    ll t, m;
    cin >> t >> m;
 
    vector <ll> a(m), pref(m);
 
    map <ll, ll> mp;
    map <ll, ll> kol;
 
    set <ll> st;
 
    ll id = 0;
 
    while(t--){
        for(int i = 0; i < m; i++){
            pref[i] = (i ? pref[i - 1] : 0) + a[i];
        }
 
        string type;
        cin >> type;
        if(type == "defragment"){
            vector <pll> c;
            for(auto i : mp)if(kol[i.fi]){
                c.p_b({i.se, i.fi});
            }
            for(int i = 0; i < m; i++)a[i] = 0;
            ll uk = 0;
            sort(all(c));
            for(auto &i : c){
                mp[i.se] = uk;
                for(int j = 0; j < kol[i.se]; j++){
                    a[uk] = 1;
                    ++uk;
                }
            }
        }else if(type == "erase"){
            ll x;
            cin >> x;
            if(kol[x]){
                ll uk = mp[x];
                while(kol[x]--){
                    a[uk] = 0;
                    ++uk;
                }
                kol[x] = 0;
            }else{
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
            }
        }else{
            ll x;
            cin >> x;
            ll ans = -1;
            for(int i = 0; i + x - 1 < m; i++){
                if(!sum(pref, i, i + x - 1)){
                    ans = i;
                    break;
                }
            }
 
            if(ans != -1){
                id++;
                mp[id] = ans;
                kol[id] = x;
                while(x--){
                    a[ans] = 1;
                    ans++;
                }
                cout << id << "\n";
            }else{
                cout << "NULL\n";
            }
        }
 
    }
 
    return 0;
}