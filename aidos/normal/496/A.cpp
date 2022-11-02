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


int n;
int a[1010];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int mn = inf;
    int mx = 0;
    for(int i = 1; i<n-1; i++){
        int cur = 0;
        for(int j = i+2; j<n; j++){
            cur = max(cur, a[j] - a[j-1]);
        }
        for(int j = 1; j<i; j++)
            cur = max(cur, a[j] - a[j-1]);
        cur = max(a[i+1] - a[i-1], cur);
        mn = min(cur, mn);
        
    }
    cout << mn << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}