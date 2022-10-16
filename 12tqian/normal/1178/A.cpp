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
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
#define trav(a, x) for (auto& a : x)

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
int main(){
    fast_io();
    int n;
    cin >> n;
    int tot = 0;
    f0r(i, n){
        int ai;
        cin >> ai;
        tot += ai;
        a.eb(ai);
    }

    vi c;
    f0r(i, n){
        if(i == 0){
            c.eb(i);
        }
        else{
            if(a[0]%2 == 0){
                if(a[i]<= a[0]/2){
                    c.eb(i);
                }
            }
            else{
                if(a[i]<= a[0]/2){
                    c.eb(i);
                }
            }
        }
    }
    int sum = 0;
    int sz = sz(c);
    f0r(i, sz){
        sum += a[c[i]];
    }
    if(tot%2 == 0){
        if(tot/2<sum){
            cout << sz << endl;
            for(int x: c) cout << x+1 << " ";
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    if(tot/2< sum){
        cout << sz << endl;
            for(int x: c) cout << x+1 << " ";
            return 0;
    }
    cout << 0 << endl;

    return 0;
}