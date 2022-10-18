/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 2e5;

int cnt[5];
char str[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        scanf("%s", str + 1);
        int n = strlen(str + 1), l = 1, r = 1;
        cnt[0] = cnt[1] = 0;
        long long ans = 0;
        for (; l <= n; l++) {
            while (r <= n) {
                if ((str[r] == '?' || (cnt[(str[r] == '1') ^ (r & 1) ^ 1] == 0)) == 0) break;
                if (str[r] != '?') cnt[(str[r] == '1') ^ (r & 1)]++;
                r++;
            }
            ans += r - l;
            if (str[l] != '?') cnt[(str[l] == '1') ^ (l & 1)]--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}