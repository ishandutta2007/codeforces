#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n;
pair<pii, int> a[105];
bool vis[10000005];
int ans[105];

bool cmp(pair<pii, int> x, pair<pii, int> y) {
    if (x.f.s ^ y.f.s) return x.f.s < y.f.s;
    return x.f.f < y.f.f;
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].f.f >> a[i].f.s;
        a[i].s = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = a[i].f.f; j <= a[i].f.s; j++) {
            if (!vis[j]) {
                vis[j] = true, ans[a[i].s] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}