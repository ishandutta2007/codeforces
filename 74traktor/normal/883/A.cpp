#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int t[maxn], inf = 1e18 + 7;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, d;
    cin >> n >> m >> a >> d;
    for (int i = 1; i <= m; ++i) cin >> t[i];
    t[m + 1] = max(n * a, t[m]);
    m++;
    sort(t + 1, t + m + 1);
    int answer = 0;
    int lst = 1;
    for (int i = 1; i <= m; ++i) {
        if (t[i] < lst) continue;
        int nxt = (lst + a - 1) / a * a;
        if (t[i] <= nxt) {
            answer++;
            lst = t[i] + d + 1;
            continue;
        }
        int cnt = max((min(t[i], n * a) - nxt + a) / a, 0ll);
        if (d < a) {
            answer += cnt;
            if (cnt != 0) lst = t[i] / a * a + d + 1;
            if (t[i] >= lst) {
                answer++;
                lst = t[i] + d + 1;
                continue;
            }
            continue;
        }
        int block = (d + a) / a;
        int imin = max(0ll, (n - nxt / a + block) / block);
        answer += min((cnt + block - 1) / block, imin);
        if (min((cnt + block - 1) / block, imin) != 0) {
            lst = nxt + a * block * max(0ll, (min((cnt + block - 1) / block, imin) - 1)) + d + 1;
        }
        if (t[i] >= lst) {
            answer++;
            lst = t[i] + d + 1;
            continue;
        }
    }
    cout << answer;
    return 0;
}