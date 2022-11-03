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

#define MAXN (int) (1e6) + 10
using namespace std;

int a[MAXN];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    int l = 0;
    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        for(int j =1; j <= x; j++){
            a[l+j] = i+1;
        }
        l+=x;
    }

    int m;
    cin >> m;
    for(int i = 0, x; i < m; i++){
        cin >> x;
        cout << a[x] << endl;
    }


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}