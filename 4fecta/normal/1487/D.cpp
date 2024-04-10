#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int a = 3; a <= 100000; a += 2) {
            int b = (a * a - 1) / 2;
            int c = b + 1;
            if (c <= n) ans++;
            else break;
        }
        printf("%d\n", ans);
    }

    return 0;
}