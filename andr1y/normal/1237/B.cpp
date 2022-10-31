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
#define N 100005
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[N], b[N], pa[N], t[N];
ll n;
ll fwsum(ll r) {
    ll res = 0;
    for (; r > 0; r -= r & -r)
        res += t[r];
    return res;
}
void fwset(ll pos, ll delt){
    for(ll i = pos;i<=n;i+=i&-i){
        t[i]+=delt;
    }
}
main(){
    FAST;
    cin >> n;
    for(ll i =1;i<=n;i++){
        cin >> a[i];
        pa[a[i]] = i;
        fwset(i, 1);
    }
    for(ll i = 1;i<=n;i++) cin >> b[i];
    ll res = 0;
    for(ll i = 1;i<=n;i++){
        ll pp = pa[b[i]];
        ll pr = fwsum(pp-1);
        if(pr > 0) res++;
        fwset(pp, -1);
    }
    cout << res;
}