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

int d[1000100];
int n;
bool a[1000100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        a[x] = 1;
        d[x] = 1;
    }
    for(int i = 1; i <= 1000000; i++){
        if(a[i]){
            for(int j = i + i;j <= 1000000; j+=i)
                if(a[j]) d[j] = max(d[j], d[i] + 1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= 1000000; i++)
        ans = max(d[i], ans);
    cout << ans << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}