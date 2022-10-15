#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005;

int n, a[MN], ans;
priority_queue<int, vector<int>, greater<>> q;

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans -= a[i];
        q.push(a[i]), q.push(a[i]);
        q.pop();
    }
    while (q.size()) ans += q.top(), q.pop();
    printf("%lld\n", ans);

    return 0;
}