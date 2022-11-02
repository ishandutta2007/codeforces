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


int n, k;
int a[10][10];
int p[11];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif    

    scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            char c;
            scanf("%c", &c);
            a[i][j] = c - '0';
        }
        scanf("\n");
    }
    for(int i = 0; i < k; i++){
        p[i] = i;
    }
    int ans = (int) 1e9;
    do{
        int x = (int) (1e9);
        int y = -x;
        for(int i = 0; i < n; i++){
            int t = 0;
            for(int j = 0; j < k; j++){
                t = t * 10 + a[i][p[j]];
            }
            x=min(x, t);
            y = max(y, t);
        }
        ans = min(y - x, ans);
    }
    while(next_permutation(p, p+k));
    cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}