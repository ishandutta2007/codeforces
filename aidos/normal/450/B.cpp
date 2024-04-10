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
const int mod = (int) 1e9 + 7;

using namespace std;

int a[111];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a[0] >> a[1];
    //x, y, y - x, -x, -y, -y + x, x
    int n;
    cin >> n;
       while(a[0] < 0) a[0] += mod;
        a[0] %= mod;
           while(a[1] < 0) a[1] += mod;
        a[1] %= mod;
    for(int i = 2; i < 100; i++){
        a[i] = a[i-1] - a[i-2];
        while(a[i] < 0) a[i] += mod;
        a[i] %= mod;
    }
    n--;
    cout << a[n % 6] << endl;;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}