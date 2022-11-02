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

    int n, m, k;
    char c[2220][2220];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        scanf("%s", &c[i]);
    }
    for(int j = 0; j<m; j++){
        int x = 0;
        for(int i = 1; i < n; i++){

            if( i<=j && c[i][j-i]  == 'R') {
                x++;
            }

            if( j + i < m && c[i][j+i] == 'L') x++;

            if( i + i < n && c[i+i][j] == 'U') x++; 
        }
        printf("%d ", x);
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}