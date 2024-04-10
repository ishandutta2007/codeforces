#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll t , n , A[MAXN] , B[MAXN] , C[MAXN] , deg[MAXN] , mark[MAXN];
vector<ll> adj[MAXN];
set<ll> st[MAXN];

void DFS(ll v){
    mark[v] = 1;
    cout << v << sep;
    for(ll u : adj[v])  if(!mark[u])    DFS(u);
}

ll MAIN(){
    cin >> n;
    
    for(ll i = 1 ; i <= n - 2 ; i++){
        cin >> A[i] >> B[i] >> C[i];
        deg[A[i]]++; deg[B[i]]++; deg[C[i]]++;
        st[A[i]].insert(i) ; st[B[i]].insert(i) ; st[C[i]].insert(i);
    }
    queue<ll> Q;
    for(ll i = 1 ; i <= n ; i++)    if(deg[i] == 1) Q.push(i);
    map<pll , ll> mark;
    vector<ll> ans;
    while(!Q.empty()){
        ll x = Q.front();
        Q.pop();
        if(deg[x] == 0) continue;
        ll ind = *st[x].begin();
        ll a = A[ind] , b = B[ind] , c = C[ind];
        if(b == x)  swap(a , b);
        if(c == x)  swap(a , c);
        if(!mark[{a , b}]){
            adj[b].push_back(a);
            adj[a].push_back(b);
        }
        if(!mark[{a , c}]){
            adj[c].push_back(a);
            adj[a].push_back(c);
        }
        deg[a]--; deg[b]-- ; deg[c]--;
        st[a].erase(ind) ; st[b].erase(ind) ; st[c].erase(ind);
        mark[{b , c}] = mark[{c , b}] = 1;
        if(deg[b] == 1) Q.push(b);
        if(deg[c] == 1) Q.push(c);
        ans.push_back(ind);
    }
    DFS(1);
    cout << endl;
    for(ll i : ans) cout << i << sep;
    cout << endl;
}

int main() {
    fast_io;
    
    cin >> t;
    while(t--){
        MAIN();
        fill(adj , adj + n + 3 , vector<ll>());
        fill(mark , mark + n + 3 , 0);
    }

    return 0;
}
/*

*/