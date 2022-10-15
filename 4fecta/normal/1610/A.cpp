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
        int n, m;
        cin >> n >> m;
        if (n == m && n == 1) printf("0\n");
        else if (min(n, m) == 1) printf("1\n");
        else printf("2\n");
    }

    return 0;
}