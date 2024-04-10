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

int cnt[555];
int a[555][555];
int ans = 0;
int n, m, q;  

void add(int x, int y = 1){
    int i = 0;
    while(i < m){
        int j = i;
        while( i<m && a[x][i]) i++;
        cnt[i - j]+=y;
        i++;
    }
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 0; i < n; i++)
        add(i);
    for(int i = 0, x, y; i < q; i++){
        scanf("%d %d", &x, &y);
        x--;
        y--;
        add(x, -1);
        a[x][y] = !a[x][y];
        add(x);
        int j = m;
        while( cnt[j] == 0) j--;
        printf("%d\n", j);
    }






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}