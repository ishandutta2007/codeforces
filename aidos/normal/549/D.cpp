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


char c[111][111];
ll b[111][111];
int n, m;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        scanf("%s", &c[i]);

    int cur = 0;

    while(true){
        int i1=-1, j1= -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'W' && b[i][j] != 1) {
                    i1 = i;
                    j1 = j;
                }
                else if(c[i][j] == 'B' && b[i][j] != -1){
                    i1 = i;
                    j1 = j;
                }
            }
        }
        if(i1==-1) break;
        cur++;
        ll need = (c[i1][j1] == 'W' ? 1 - b[i1][j1]: -1 - b[i1][j1]);
        for(int i = 0; i <= i1; i++)
            for(int j = 0; j <=j1; j++)
                b[i][j] += need;    
    }
    cout << cur << endl;
    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}