#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

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
const int MAX = 1e3 + 5;

const ll INF = 1e16;

static vector<pair<int, ll>> adj[MAX];
static vector<pair<int, ll>> adj1[MAX];

ll dist[MAX];
int par[MAX];

void dijkstra(int st, int end) {
    fill(dist, dist + MAX, INF);

    dist[st] = 0;

    // <distance, <previous vertex, current vertex>>
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>> >, greater<pair<ll, pair<int ,int>> > > pq;
    pq.emplace(0, make_pair(st, st));

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        ll d = top.first;
        int prev = top.second.first;
        int cur = top.second.second;

        if(d > dist[cur])
        	continue;

        par[cur] = prev;

        for(auto v: adj[cur]){
        	int nxt = v.first;
        	ll w = v.second;
            if (dist[nxt] > dist[cur] + w) {
                dist[nxt] = dist[cur] + w;
                pq.emplace(dist[nxt], make_pair(cur, nxt));
            }
        }
    }
}
int ind[MAX][MAX];
int main(){
    fast_io();
    int n, m, s, t;
    ll L;
    cin >> n >> m >> L >> s >>t;
    f0r(i, m){
        int st, ed;
        ll w;
        cin >> st >> ed >> w;
        adj[st].eb(mp(ed, w));
        adj[ed].eb(mp(st, w));
        adj1[st].eb(mp(ed, w));
        adj1[ed].eb(mp(st, w));
        ind[st][ed] = sz(adj[st])-1;
        ind[ed][st] = sz(adj[ed]) - 1;
    }
    f0r(i, n){
        f0r(j, sz(adj1[i])){
            if(adj1[i][j].s == 0){
                adj[i][j].s = INF;
            }
        }
    }
    dijkstra(s, t);
    if(dist[t] < L){
        cout <<"NO" << endl;
        return 0;
    }
    f0r(i, n){
        f0r(j, sz(adj1[i])){
            if(adj1[i][j].s == 0){
                adj[i][j].s = 1;
            }
        }
    }
    dijkstra(s, t);
    if(dist[t]>L){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int cur =t;
    while(cur != par[cur]){
        int nxt = par[cur];
        int loc1 = ind[cur][nxt];
        int loc2 = ind[nxt][cur];
        if(adj1[cur][loc1].s != 0){
            cur = par[cur];
            continue;
        }
        adj1[cur][loc1].s = -1;
        adj1[nxt][loc2].s = -1;
        cur = par[cur];
    }
    f0r(i, n){
        f0r(j, sz(adj1[i])){
            if(adj1[i][j].s == 0){
                adj[i][j].s = INF;
            }
        }
    }
    while(dist[t] <L){
        cur = t;
        while(cur!= par[cur]){
            int nxt = par[cur];
            int loc1 = ind[cur][nxt];
            int loc2 = ind[nxt][cur];
            if(adj1[cur][loc1].s == -1){
                adj[cur][loc1].s += L - dist[t];
                adj[nxt][loc2].s += L - dist[t];
                break;
            }
            cur = par[cur];
        }
        if(cur == s){
            break;
        }
        dijkstra(s, t);

    }
    f0r(i, n){
        for(auto nxt: adj[i]){
            int j = nxt.f;
            if(i>j){
                continue;
            }
            cout << i << " " << j << " " << nxt.s << endl;
        }
    }
    return 0;
}