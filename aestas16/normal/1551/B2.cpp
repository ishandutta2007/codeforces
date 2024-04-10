// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

int a[N + 10], cnt[N + 10], ans[N + 10];
vector<int> p[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), k = fr();
        ans[0] = 0;
        int pos = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), cnt[a[i]]++, p[a[i]].push_back(i);
        for (int i = 1; i <= n; i++)
            if (cnt[i] >= k) {
                for (int j = 0; j < k; j++) ans[p[i][j]] = j + 1;
            } else ans[0] += cnt[i];
        ans[0] = (ans[0] / k) * k;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] >= k) continue;
            if (ans[0] == 0) continue;
            for (int j = 0; j < cnt[i]; j++)
                if (ans[0]) ans[p[i][j]] = pos % k + 1, pos = ans[p[i][j]], ans[0]--;
        }
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]), cnt[i] = 0, ans[i] = 0, p[i].clear();
        puts("");
    }
    return 0;
}