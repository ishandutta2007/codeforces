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
using namespace std;
ll kid[N];
ll bs[N], bsc = 1;
ll vb[N];
ll vc = 0;
void dfs(ll v){
    vc++;
    vb[v] = bsc;
    if(vb[kid[v]] == 0) dfs(kid[v]);
}
main(){
    FAST;
    ll q;
    cin >> q;
    while(q--){
        bsc = 1;
        ll n;
        cin >> n;
        for(ll i = 1;i<=n;i++){
            vb[i] = 0;
            ll j;
            cin >> j;
            kid[i] = j;
        }
        for(ll i = 1;i<=n;i++){
            if(vb[i] == 0){
                vc = 0;
                dfs(i);
                bs[bsc++] = vc;
            }
        }
        for(ll i = 1;i<=n;i++) cout << bs[vb[i]] << " ";
        cout << endl;
    }
}