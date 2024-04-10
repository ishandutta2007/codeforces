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
vi a;
const int MAX = 3e5+5;
set<pii> s;
int mx[MAX];
int mn[MAX];
vi indices;
int main(){
    fast_io();
    int n;
    cin >> n;
    double k = 1e9;
    f0r(i, n){
        int ai;
        cin >> ai;
        a.eb(ai);
        s.insert(mp(ai, i+1));
    }
    f0r(i, MAX){
        mn[i] = 1e9;
    }
    int it = 0;
    for(auto x: s){
        indices.eb(x.s);
    }
    for(int i = n-1; i>= 0; i--){
        if(i == n-1){
            mx[i] = indices[i];
            mn[i] = indices[i];
        }
        else{
            mx[i] = max(indices[i],  mx[i+1]);
            mn[i] = min(indices[i], mn[i+1]);
        }
        it++;
    }
    it = 0;
    for(auto x: s){
        if (it == n-1){
            continue;
        }
        else{
            int val = x.f;
            int id = x.s;
            int mnID = mn[it+1];
            int mxID = mx[it+1];
            int diff = max(abs(id -mnID), abs(id- mxID));
            if(diff == 0) continue;
            k = min(k, (double) val/diff);

        }
        it++;
    }
    cout << (int) k<< endl;
    return 0;
}