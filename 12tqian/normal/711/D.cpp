#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
const int MAX = 2e5 +5;
const int MOD = 1e9 + 7;

vector<int> adj[MAX];
int vis[MAX];
vi cycles;
int par [MAX];
int depth [MAX];
map<pii, int> roads;
ll modpow (ll b, ll p) {
     return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD;
}
ll mulmod(ll a, ll b){
    ll res = 0;
    a = a % MOD;
    while (b > 0){
        if (b % 2 == 1)
            res = (res + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return res % MOD;
}
bool found = false;
void dfs(int src){
    vis[src] = 1;
    for(int neigh: adj[src]){
        if(vis[neigh] == 1 && neigh != par[src] && found == false){
            vi vertices;
            vertices.eb(neigh);
            vertices.eb(src);
            int x = src;
            int y = neigh;
            while(x!= y){
                if(depth[x] > depth[y]){
                    swap(x, y);
                }
                y = par[y];
                if(x!= y){
                    vertices.eb(y);
                }
            }
            cycles.eb(vertices.size());
            found = true;
            continue;
        }
        if(vis[neigh] == 0){
            par[neigh] = src;
            depth[neigh] = depth[src] + 1;
            dfs(neigh);
        }
    }
}
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        int d;
        cin >> d;
        d--;
        map<pii, int> :: iterator it;
        it = roads.find(mp(min(i, d), max(i, d)));
        if(it != roads.end()){
            roads[mp(min(i, d), max(i, d))] += 1;
        }
        else{
            roads[mp(min(i, d), max(i, d))] = 1;
            adj[d].eb(i);
            adj[i].eb(d);
        }

    }
    for(auto it: roads){
        if(it.s == 2){
            cycles.eb(2);
        }
    }

    f0r(i, n){
        if(vis[i] == 0){
            found = false;
            dfs(i);
        }
    }
    ll ans = 1;
    ll sum = 0;
    for(int i:cycles){
        sum += i;
    }
    sum = n-sum;
    for(int i: cycles){
        ans = mulmod(ans, ((modpow(2, i)-2)%MOD+MOD)%MOD);
    }
    ans = mulmod(ans, modpow(2, sum));
    cout << ans << endl;;
    return 0;
}