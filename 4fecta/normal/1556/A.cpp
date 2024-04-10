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
        int c, d;
        cin >> c >> d;
        if (c % 2 != d % 2) {printf("-1\n"); continue;}
        if (c == 0 && d == 0) printf("0\n");
        else if (c == d) printf("1\n");
        else printf("2\n");
    }

    return 0;
}