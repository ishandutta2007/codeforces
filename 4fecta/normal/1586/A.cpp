#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

bool prime(int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, a[105];
        cin >> n;
        int sum = 0;
        int id = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i], sum += a[i];
            if (a[i] % 2) id = i;
        }
        if (!prime(sum)){
            printf("%d\n", n);
            for (int i = 1; i <= n; i++) printf("%lld ", i);
            printf("\n");
        } else {
            printf("%d\n", n - 1);
            for (int i = 1; i <= n; i++) if (i != id) printf("%lld ", i);
            printf("\n");
        }
    }

    return 0;
}