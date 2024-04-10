#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005;

int n, m, a[MN], cnt[MN], b[MN], pos[MN], vis[MN];

int32_t main() {
    boost();

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int cor = n - 2 * m; //at least 1/3 of N
        for (int i = 1; i <= n; i++) {
            int sh = (i - a[i] + n) % n;
            cnt[sh]++;
        }
        vector<int> out;
        for (int i = 0; i < n; i++) {
            if (cnt[i] < cor) continue;
            //at most 3 can get to this point
            for (int j = 1; j <= n; j++) {
                vis[j] = 0;
                b[j] = (j - i + n) % n;
                if (!b[j]) b[j] = n;
                pos[b[j]] = j;
            }
            int num = 0;
            for (int j = 1; j <= n; j++) {
                //printf("%d %d\n", j, pos[a[j]]);
                if (vis[j]) continue;
                int len = 1, cur = j;
                vis[cur] = 1;
                while (pos[a[cur]] != j) len++, cur = pos[a[cur]], vis[cur] = 1;
                num += len - 1;
            }
            if (num <= m) out.push_back(i);
        }
        printf("%lld", out.size());
        for (int p : out) printf(" %lld", p);
        printf("\n");
        for (int i = 0; i < n; i++) cnt[i] = 0;
    }
    
    return 0;
}