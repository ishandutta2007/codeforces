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
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const double PI = 4 * atan(1);

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
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

template<typename A, typename B> ostream& operator <<(ostream &cout, pair< A, B> const &p) {return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator <<(ostream &cout, vector<A> const &v){
    cout <<"["; for(int i = 0; i<v.size(); i++) {if(i) cout <<", "; cout << v[i];} return cout << "]";
}
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
const int MAX  = 1e5 + 5;
vi adj[MAX];
int vis[MAX];
int num[MAX];
void dfs(int src, int comp){
    vis[src] = 1;
    num[comp]++;
    for(int nxt:adj[src]){
        if(vis[nxt] == 0){
            dfs(nxt, comp);
        }
    }
}
int main(){
    fast_io();
    int n, k;
    cin >> n >> k;
    f0r(i, k){
        int u, v;
        cin >> u >> v;
        u--;v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    int c = 0;
    f0r(i, n){
        if(vis[i] == 0){
            dfs(i, c);
            c++;
        }
    }
    int fin = 0;
    f0r(i, n){
        if(num[i] == 0) continue;
        fin += (num[i]-1);
    }
    cout << k - fin << endl;
    return 0;
}