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

int n, l;

vector < int > v;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> l;
    for(int i = 0, x; i<n; i++){
        cin >> x;
        v.pb( x );
    }
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    double ans = 0.0;
    for(int i = 1; i < v.size(); i++){
        ans = max(ans, (v[i] - v[i-1])/2.0);
    }
    ans = max(ans, v[0] - 0.0);
    ans = max(ans, l - v.back() - 0.0);
    printf("%.12lf", ans);



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}