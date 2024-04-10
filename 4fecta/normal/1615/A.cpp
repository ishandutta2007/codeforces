#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int a[105];
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        if (sum % n )printf("1\n");
        else printf("0\n");
    }

    return 0;
}