#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, m, r, c, R[1005], C[1005];

int main() {
    boost();

    cin >> n >> m;
    R[1] = C[1] = R[n] = C[n] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> r >> c;
        R[r] = 1;
        C[c] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!C[i]) ans++;
        if (!R[i]) ans++;
    }
    if (n % 2 && !C[n / 2 + 1] && !R[n /2 + 1]) ans--;
    printf("%d\n", ans);

    return 0;
}