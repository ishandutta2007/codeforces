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

#define MAXN (int) (1e7)+10
using namespace std;


int n;
int a[MAXN];
int b[MAXN];


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        a[x]++;
    }
    memset(b, -1, sizeof b);
    b[1] = 0;
    for(int i = 2; i < MAXN; i++){
        int &res = b[i];
        if( res == -1){
            for(int j = i+i; j < MAXN; j+=i){
                res += a[j];
                b[j] = 0;
            }
            res += a[i] + 1;
        }
        res += b[i-1];
    }
    int m;
    scanf("%d", &m);
    for(int i = 0, l, r; i<m; i++){
        scanf("%d%d", &l, &r);
        r = min(r, MAXN-1);
        if( l > r){
            printf("0\n");
            continue;
        }
        printf("%d\n", b[r] - b[l-1]);
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}