#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-12;

#ifdef LOCAL
const ll MAX = 5e5 + 1;
#else
const ll MAX = 7e6 + 1;
#endif

int main() {

    sync;

#ifdef LOCAL
    input;
#else

#endif

    int n, k, s;
    cin >> n >> k >> s;

    ll x = 1;
    for(int i = 0; i < k; i++)
    	x *= s;

    ll ar[n];
    for(int i = 0; i < n; i++)
    	cin >> ar[i];

    ll *dp1 = new ll[n + 2];
    ll *dp2 = new ll[n + 2];
    dp1++, dp2++;
    dp1[-1] = dp2[-1] = dp1[n] = dp2[n] = 0;
    for(int i = 0; i < n; i++){
    	dp1[i] = ar[i] | dp1[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
    	dp2[i] = ar[i] | dp2[i + 1];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++)
    	ans = max(ans, dp1[i - 1] | dp2[i + 1] | (ar[i] * x));

    cout << ans;

}