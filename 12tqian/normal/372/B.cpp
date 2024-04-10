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
const int MAX = 45;
int grid[MAX][MAX];
int prefix[MAX][MAX];
int big[MAX][MAX][MAX][MAX];
int compute(int a, int b, int c, int d){
    if(a>c){
        swap(a, c);
        swap(b, d);
    }
    int sum = prefix[c][d];
    if(a>0){
        sum -= prefix[a-1][d];
    }
    if(b>0){
        sum -= prefix[c][b-1];
    }
    if(a>0 && b>0){
        sum += prefix[a-1][b-1];
    }
    return sum;
}
int check(int a, int b, int c, int d){
    if(compute(a, b, c, d)){
        return 0;
    }
    return 1;
}
int calc(int a, int b, int c, int d){
    if(a>c){
        swap(a, c);
        swap(b, d);
    }
    int sum = big[c][d][c][d];
    if(a>0){
        sum -= big[c][d][a-1][d];
    }
    if(b>0){
        sum -= big[c][d][c][b-1];
    }
    if(a>0 && b>0){
        sum += big[c][d][a-1][b-1];
    }
    return sum;
}
int main(){
    fast_io();
    int n, m, q;
    cin >> n >> m>> q;
    string temporary;
    getline(cin, temporary);
    string line;
    f0r(i, n){
        getline(cin, line);
        f0r(j, m){
            grid[i][j] = line[j] - '0';
        }
    }

    f0r(i, n){
        int run = 0;
        f0r(j, m){
            run += grid[i][j];
            if(i == 0){
                prefix[i][j] = run;
            }
            else{
                prefix[i][j] = run + prefix[i - 1][j];
            }
        }
    }
    f0r(i, n){
        f0r(j, m){
            f0r(a, i+1){
                int run = 0;
                f0r(b, j+1){
                    run += check(a, b, i, j);
                    if(a == 0){
                        big[i][j][a][b] = run;
                    }
                    else{
                        big[i][j][a][b] = big[i][j][a-1][b] + run;
                    }
                }
            }
        }
    }
    f0r(k, q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int ans = 0;
        f1r(i, a, c+1){
            f1r(j, b, d+1){
                ans += calc(a, b, i, j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}