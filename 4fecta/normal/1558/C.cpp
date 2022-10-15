#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 2050;

int t, n, a[MN];
vector<int> out;

void rev(int len) {
    reverse(a + 1, a + len + 1);
    out.push_back(len);
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 != i % 2) ok = 0;
        }
        if (!ok) {printf("-1\n"); continue;}
        out.clear();
        while (n > 1) {
            int pose = 0, poso = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == n) poso = i;
                if (a[i] == n - 1) pose = i;
            }
            rev(poso);
            for (int i = 1; i <= n; i++) {
                if (a[i] == n) poso = i;
                if (a[i] == n - 1) pose = i;
            }
            rev(pose - 1);
            for (int i = 1; i <= n; i++) {
                if (a[i] == n) poso = i;
                if (a[i] == n - 1) pose = i;
            }
            rev(pose + 1);
            rev(3);
            rev(n);
            n -= 2;
        }
        printf("%lld\n", (int) out.size());
        for (int p : out) printf("%lld ", p);
        printf("\n");
    }

    return 0;
}