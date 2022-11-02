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

int a[111];
int n;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    int k;
    cin >> k;
    for(int i  =0, x; i < k; i++){
        cin >> x;
        a[x] = 1;
    }
    cin >> k;
    for(int i  =0, x; i < k; i++){
        cin >> x;
        a[x] = 1;
    }
    for(int i = 1; i <= n; i++){
        if( !a[i]){
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}