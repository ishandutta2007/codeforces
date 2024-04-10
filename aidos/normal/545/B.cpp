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


char a[maxn], b[maxn], c[maxn];
int cnt = 0;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%s\n%s\n", &a, &b);
    int n = strlen(a);
    for(int i = 0; i < n; i++){
        cnt += (a[i] != b[i]);
    }
    if(cnt & 1) {
        printf("impossible\n");
        return 0;
    }
    cnt=0;
    for(int i = 0; i < n; i++){
        if(cnt > 0){
            printf("%c", a[i]);
            cnt -= (a[i] != b[i]);
        }
        else {
            printf("%c", b[i]);
            cnt += (a[i] != b[i]);
        }
    }




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}