#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
double a[111][111], d[111][111];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;

    double ans = 0.0;
    for(int i = 0; i < n; i++){
        cin >> d[i][0];
        a[i][0] = 1-d[i][0];
        ans = max(ans, d[i][0]);
    }                
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            d[i][j] = 0.0;
            a[i][j] = 0.0;
            for(int k = j-1; k < i; k++){
                if( d[k][j-1] * (a[i][0]) + a[k][j-1] * d[i][0] > d[i][j]){
                    d[i][j] = d[k][j-1] * (1-d[i][0]) + a[k][j-1] * d[i][0];
                    a[i][j] = a[k][j-1] * (1-d[i][0]);
                }
                else if( fabs(d[k][j-1] * (1-d[i][0]) + a[k][j-1] * d[i][0] - d[i][j]) < 1e-15 && a[k][j-1] * (1-d[i][0]) > a[i][j]){
                    a[i][j] = a[k][j-1] * (1-d[i][0]);
                }
                ans = max(d[i][j], ans);
            }
//            cout << i+1 << " " << j + 1 << " " << d[i][j] << endl;
        }
    }
    printf("%.16lf", ans);
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}