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

#define MAXN (int) (1e5) + 10
using namespace std;
int a[300100];
ll ans;
void add(int l, int r, ll sum){
    if( l == r){
        ans += sum;
        return;
    }
    ans += sum;
    add(l, l, a[l]);
    add(l+1, r, sum - a[l]);
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    ll sum = 0;
    ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a +n);
    add(0, n-1, sum);
    cout << ans << endl;
    #ifdef LOCAL
    #endif
    return 0;
}