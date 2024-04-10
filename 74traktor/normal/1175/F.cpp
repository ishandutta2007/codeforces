#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
int a[maxn], cnt[maxn], nxt[maxn], st[maxn], go[maxn];

inline int solve(int n) {
    int ans = 0, j = 1, ptr = 1;
    for (int i = 1; i <= n; ++i) cnt[i] = 0, nxt[i] = n + 1;
    for(int i = 1; i <= n; ++i) {
        while (j <= n && cnt[a[j]] == 0) {
            cnt[a[j]]++;
            ++j;
        }
        go[i] = j - 1;
        cnt[a[i]]--;
    }
    for (int i = n; i >= 1; --i) {
        while (ptr > 1 && a[st[ptr - 1]] < a[i]) ptr--;
        if (ptr != 1) nxt[i] = st[ptr - 1] - 1;
        st[ptr++] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            int mx = 0, pos = 0;
            for (int j = i - 1; j >= 1; --j) {
                if (a[j] == 1) break;
                if (a[j] > mx) {
                    mx = a[j], pos = j;
                }
                //cout << j << " " << mx << " " << nxt[pos] << " "<< go[j] << endl;
                if (nxt[pos] >= j + mx - 1 && go[j] >= j + mx - 1 && j + mx - 1 >= i) ans++;
            }
        }
    }
    //exit(0);
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ans = solve(n);
    for (int i = 1; i <= n / 2; ++i) swap(a[i], a[n - i + 1]);
    ans += solve(n);
    for (int i = 1; i <= n; ++i) if (a[i] == 1) ans++;
    cout << ans << '\n';
    return 0;
}