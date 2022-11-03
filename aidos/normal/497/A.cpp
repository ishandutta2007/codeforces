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
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


int n, m;
char c[1010][1010];
int ok[1010];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif  
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s\n", &c[i]);
    }
    int cnt = 0;
    for(int j = 0; j<m; j++){
        int x = 0;
        for(int i = 0; i+1 < n; i++){
            if( !ok[i] && c[i][j] > c[i+1][j] ) x = 1;
        }
        if( x == 0){
            for(int i = 0; i+1 < n; i++){
                if( !ok[i] && c[i][j] < c[i+1][j] ) ok[i] = 1;
            }
        }
        else cnt++;
    }
    cout << cnt << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}