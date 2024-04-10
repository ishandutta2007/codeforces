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
const int MAX = 2e5 + 5;
template<int SZ> struct DSU{
    int par[SZ], sz[SZ];
    DSU(){
        for(int i = 0; i<SZ; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int big(int i){
        return(sz[get(i)]);
    }
    int get(int x){
        if(par[x] != x){
            par[x] = get(par[x]);
        }
        return par[x];
    }
    bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x == y){
            return false;
        }
        if(sz[x] < sz[y]){
            swap(x, y);
        }
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
};
DSU<MAX> row;
DSU<MAX> col;

vi c[MAX];
vi r[MAX];
int main(){
    fast_io();
    int n, m, q;
    cin >> n >> m >> q;
    f0r(i, q){
        int ri,ci;
        cin >> ri >> ci;
        ri--; ci--;
        r[ri].eb(ci);
        c[ci].eb(ri);
    }
    f0r(i, n){
        for(int x: r[i]){
            col.unite(x, r[i][0]);
        }
    }
    f0r(i, m){
        for(int x: c[i]){
            row.unite(x, c[i][0]);
        }
    }
    map<int, int> mr;
    map<int, int> mc;
    f0r(i, n){
        mr[row.get(i)]++;
    }
    f0r(i, m){
        mc[col.get(i)]++;
    }
    int badr = 0;
    int badc = 0;
    f0r(i, n){
        if(sz(r[i]) == 0 && row.big(i) == 1){
            badr++;
        }
    }
    f0r(i, m){
        if(sz(c[i]) == 0 && col.big(i) == 1){
            badc++;
        }
    }
    //cout << badc << " " << badr << endl;
    int goodr = sz(mr) - badr;
    int goodc = sz(mc) - badc;
    assert(goodr == goodc);
    cout << min(goodr, goodc) - 1 + badc + badr + abs(goodr-goodc)<< endl;
    return 0;
}