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

#define MAXN (int) (1e7)
using namespace std;

char c[111][111];
int n;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d\n", &n);

    for(int i = 0;  i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%c", &c[i][j]);
        }
        scanf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int x = dx[k] + i;
                int y = dy[k] + j;
                if( x < 0 || x >= n || y >= n || y < 0) continue;
                if( c[x][y] == 'o') cnt++;
            }
            if( cnt%2){
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}