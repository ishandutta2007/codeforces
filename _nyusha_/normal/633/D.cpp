#include<bits/stdc++.h>

using namespace std;

int const maxn = 1005;
int a[maxn], add[maxn];
unordered_map < int, int > cnt;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = -1000000001;
    for (int i = 1; i <= n; ++i) cnt[a[i]]++;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i - j != 1 && j - i != 1) {
                if (i == j || a[i] == a[i - 1] || a[j] == a[j - 1])continue;
            }
            int cur = 2, ptr = 1;
            cnt[a[i]]--, cnt[a[j]]--;
            add[ptr++] = a[i], add[ptr++] = a[j];
            int lst_x = a[i], lst_y = a[j];
            while (1) {
                if (cnt[lst_x + lst_y] == 0) {
                    break;
                }
                add[ptr++] = lst_x + lst_y;
                cur++;
                cnt[lst_x + lst_y]--;
                int to = lst_x + lst_y;
                lst_x = lst_y, lst_y = to;
            }
            ans = max(ans, cur);
            for (int pos = 1; pos < ptr; ++pos) cnt[add[pos]]++;
        }
    }
    cout << ans << '\n';
    return 0;
}