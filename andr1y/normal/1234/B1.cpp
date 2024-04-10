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
#define N 200005
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll cnt[N];
map<ll, ll> sz, szlp;
ll DD(ll x){
    if(sz[x] == 0){
        ll nw = sz.size();
        sz[x] = nw;
        szlp[nw] = x;
    }
    return sz[x];
}
main(){
    FAST;
    ll n, k;
    cin >> n >> k;
    ll la = 0, c;
    for(ll i = 0;i<=n;i++) cnt[i] = NINF;
    for(ll i  =0;i<n;i++){
        cin >> c;
        c = DD(c);
        if(la - cnt[c] >= k){
            cnt[c] = ++la;
        }
    }
    multiset<pll, greater<pll>> ms;
    for(ll i  =1;i<=n;i++){
        if(cnt[i]!=0 && cnt[i]!=NINF) ms.insert({cnt[i], i});
    }
    ll ou =min<ll>(ms.size(), k);
    cout << ou << endl;
    for(ll i =0;i<ou;i++){
        cout << szlp[(*(ms.begin())).y] << " ";
        ms.erase(ms.begin());
    }
}