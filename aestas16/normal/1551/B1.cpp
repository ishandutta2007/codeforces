// 392699

#include <bits/stdc++.h>

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &...a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 50;

char str[N + 10];
int tot[5], cnt[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s", str + 1);
        memset(cnt, 0, sizeof(cnt));
        int n = strlen(str + 1), col = 0;
        tot[0] = tot[1] = 0;
        for (int i = 1; i <= n; i++) {
            cnt[str[i] - 'a']++;
            if (cnt[str[i] - 'a'] == 1) tot[0]++;
            else if (cnt[str[i] - 'a'] == 2) tot[1]++, tot[0]--;
        }
        printf("%d\n", tot[1] + tot[0] / 2);
    }
    return 0;
}