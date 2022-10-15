#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

struct seg {
    int l, r, c;
};

int n;
seg a[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        if (k > (n + 1) / 2) {printf("-1\n"); continue;}
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j && i % 2 == 1 && k) printf("R"), k--;
                else printf(".");
            }
            printf("\n");
        }
    }

    return 0;
}