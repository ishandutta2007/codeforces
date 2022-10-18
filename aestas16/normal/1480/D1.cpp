/*
    I will never forget it.
*/

// 392699

#include <cstdio>
#include <vector>

using std::vector;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5, INF = 0x3f3f3f3f, INF2 = 0x7f7f7f7f;

int ans, a[N + 10];
vector<int> qwq[N + 10];

struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;

signed main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    int n = fr(), top1 = 0, top2 = 0;
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = n; i; i--) qwq[a[i]].push_back(i);
    for (int i = 1; i <= n; i++) {
        int tmp1 = qwq[top1].size() ? qwq[top1].back() : INF;
        int tmp2 = qwq[top2].size() ? qwq[top2].back() : INF;
        if (a[i] == top1) tmp1 = INF2;
        if (a[i] == top2) tmp2 = INF2;
        // printf("%d %d\n", tmp1, tmp2);
        if (tmp1 < tmp2)
            ans += (top1 != a[i]), top1 = a[i];
        else
            ans += (top2 != a[i]), top2 = a[i];
        qwq[a[i]].pop_back();
    }
    printf("%d\n", ans);
    return 0;
}
/*
7
1 2 2 3 4 2 2
1 2 3 2
2 4 2
*/