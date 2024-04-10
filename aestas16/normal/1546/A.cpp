/*
     []
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e2;

int a[N + 10], b[N + 10];

vector<int> qwq;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        qwq.clear();
        int n = fr(), sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), sum1 += a[i];
        for (int i = 1; i <= n; i++) {
            fr(b[i]), sum2 += b[i];
            if (b[i] < a[i]) {
                for (int j = b[i] + 1; j <= a[i]; j++) qwq.push_back(i);
            }
        }
        if (sum1 != sum2) {
            puts("-1");
            continue;
        }
        printf("%d\n", qwq.size());
        for (int i = 1; i <= n; i++) {
            if (b[i] > a[i]) {
                for (int j = a[i] + 1; j <= b[i]; j++) printf("%d %d\n", qwq.back(), i), qwq.pop_back();
            }
        }
    }
    return 0;
}