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
typedef vector<pair<char, ll>>  block;
block blocker(string s){
    char now = 0;
    ll nowsz = 0;
    block res;
    for(ll i =0;i<s.length();i++){
        if(i == 0){
            now = s[i];
            nowsz++;
            continue;
        }
        if(now == s[i]){
            nowsz++;
        }else{
            res.pb({now, nowsz});
            now = s[i];
            nowsz = 1;
        }
    }
    res.pb({now, nowsz});
    return res;
}
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        string s, t;
        cin >> s >> t;
        block bs = blocker(s);
        block bt = blocker(t);
        if(bs.size() != bt.size()) cout << "NO" << endl;
        else{
            bool brk = false;
            for(ll j = 0;j<bs.size();j++){
                if(bs[j].x != bt[j].x || bt[j].y < bs[j].y){
                    cout << "NO" << endl;
                    brk = true;
                    break;
                }
            }
            if(brk) continue;
            else cout << "YES" << endl;
        }
    }
}