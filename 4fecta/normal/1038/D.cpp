#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, a[500005];
ll sum = 0;
int mn = INT_MAX, mx = INT_MIN;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += abs(a[i]), mn = min(mn, a[i]), mx = max(mx, a[i]);
    if (n == 1) printf("%d\n", a[1]);
    else if (mx < 0 && n > 1) printf("%lld\n", sum - 2 * abs(mx));
    else if (mn > 0 && n > 1) printf("%lld\n", sum - 2 * mn);
    else printf("%lld\n", sum);

    return 0;
}