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

const int N = 2e5;

string str[N + 10];

struct Node {
    int cnt, len;
    bool operator < (const Node &rhs) const {
        return cnt - (len - cnt) > rhs.cnt - (rhs.len - rhs.cnt);
    }
} a[N + 10];

/*
cnt / len > cnt / len
*/

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> str[i];
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j <= n; j++) {
                a[j].cnt = 0, a[j].len = str[j].length();
                for (int k = 0; k < a[j].len; k++) a[j].cnt += str[j][k] == (i + 'a');
            }
            sort(a + 1, a + 1 + n);
            int cnt = 0, tot = 0, qwq = 0;
            for (int j = 1; j <= n; j++) {
                ans = max(ans, qwq);
                if (cnt + a[j].cnt > tot + a[j].len - a[j].cnt) {
                    cnt += a[j].cnt, tot += a[j].len - a[j].cnt;
                    qwq++;
                    // goto cat;
                }
            }
            ans = max(ans, qwq);
            cat:;
            // printf("ans = %d\n", ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}