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
const int MAXM = 55;
const int MAXN = 1e4+5;
int idx[MAXM][MAXN];
vi s;
int main(){
    fast_io();
    int m;cin >>m;
    int n; cin>> n;
    f0r(i, m){
        int si;
        cin >> si;
        s.eb(si);
        f0r(j,si){
            cin >> idx[i][j];
            idx[i][j]--;
        }
    }
    f0r(i, m){
        f1r(j, i+1, m){
            vi v;
            f0r(k, n){
                v.eb(0);
            }
            f0r(k, s[i]){
                v[idx[i][k]]++;
            }
            f0r(k, s[j]){
                v[idx[j][k]]++;
            }
            bool isTrue = true;
            f0r(k, n){
                if(v[k] == 2){
                    isTrue =false;
                    break;
                }
            }
            if(isTrue){
                        cout  << "impossible" << endl;;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    return 0;
}