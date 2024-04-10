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
        int a, b;
        cin >> a >> b;
        set<int> out;
        int n = a + b;
        int cnta = n / 2, cntb = (n + 1) / 2;
        if (a > b) swap(a, b);
        for (int i = 0; i <= a; i++) {
            int k = i;
            k += cnta - (a - i);
            out.insert(k);
            k = i;
            k += cntb - (a - i);
            out.insert(k);
        }
        printf("%lld\n", (int) out.size());
        for (int p : out) printf("%lld ", p);
        printf("\n");
    }

    return 0;
}