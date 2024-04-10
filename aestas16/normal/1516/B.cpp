/*
    I will never forget it.
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

const int N = 2e3;

int a[N + 10], xsum[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), pos = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), xsum[i] = xsum[i - 1] ^ a[i];
        if (xsum[n] == 0) {
            puts("YES");
            continue;
        }
		for (int i = 1; i <= n; i++) 
			if (xsum[i] == xsum[n]) {
				pos = i; 
				break;
		}
        for (int i = pos + 1; i <= n; i++)
            if (xsum[i] == 0) {
                puts("YES");
                goto cat;
            }
        puts("NO");
        cat:;
    }
    return 0;
}