/*
    I will never forget it.
*/
 
// 392699
 
#include <bits/stdc++.h>
 
#define int long long
 
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
 
const int N = 1e5, INF = 0x7f7f7f7f;
 
int a[N + 10];
 
struct OI {
    int RP, score;
} CSPS2021, NOIP2021;
 
signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), ans = 0, Min, p1, p2;
        for (int i = 1; i <= n; i++) fr(a[i]);
        sort(a + 1, a + n + 1), Min = INF, p1 = n;
        for (int i = 2; i <= n; i++) {
            Min = min(Min, a[i] - a[i - 1]);
            if (Min < a[i]) {
                p1 = i - 1;
                break;
            }
        }
        p2 = 1, Min = INF;
        for (int i = n - 1; i; i--) {
            Min = min(Min, a[i + 1] - a[i]);
            if (Min < a[n]) {
                p2 = i + 1;
                break;
            }
        }
        printf("%lld\n", max(p1, n - p2 + 1));
    }
    return 0;
}