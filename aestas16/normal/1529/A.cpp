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
 
const int N = 1e2;
 
int n, a[N + 10];
 
struct OI {
    int RP, score;
} CSPS2021, NOIP2021;
 
int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int tot, ans = 0;
        fr(n);
        tot = n;
        for (int i = 1; i <= n; i++) fr(a[i]);
        while (1) {
            int sum = 0, cnt = 0;
            for (int i = 1; i <= n; i++) sum += a[i];
            for (int i = 1; i <= n; i++)
                if (sum < a[i] * tot) cnt++, a[i] = 0;
            if (cnt == 0) break;
            ans += cnt, tot -= cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}