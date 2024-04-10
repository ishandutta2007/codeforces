#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const int MAX = 1e5 + 5;
const ll INF = 1e12;
static vector<pair<int, ll>> adj [MAX];
vi a;
static int vis[MAX];
static int st[MAX];
static ll dist[MAX];
void bfs(int src){
    list<int> q;
    vis[src] = 1;
    q.pb(src);
    while(!q.empty()){
        int s = q.front();
        vis[s] = 1;
        q.pop_front();
        for(pair<ll, ll> x: adj[s]){
            ll nxt = x.f;
            if(!st[nxt]){
                dist[nxt] = min(dist[nxt], x.s);
            }
            else{
                if(vis[x.f] == 0){
                    q.pb(x.f);
                }
            }
        }
    }
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    f0r(i, m){
        ll u, v;
        ll l;
        cin >> u >> v >> l;
        u--;
        v--;
        adj[u].eb(mp(v, l));
        adj[v].eb(mp(u, l));
    }
    f0r(i, k){
        int d;
        cin >> d;
        d--;
        st[d] = 1;
        a.eb(d);
    }
    f0r(i, n){
        dist[i] = INF;
    }
    if(k == 0 || k == n){
        cout << -1;
        return 0;
    }
    f0r(i, a.size()){
        if(vis[a[i]] == 0){
            bfs(a[i]);
        }
    }
    ll ans = INF;
    f0r(i, n){
        if(st[i] == 0){
            ans = min(ans, dist[i]);
        }
    }
    if(ans == INF){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}