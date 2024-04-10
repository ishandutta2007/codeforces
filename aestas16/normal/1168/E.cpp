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

const int N = 12;

int arr[(1 << N) + 10], a[(1 << N) + 10], ans[(1 << N) + 10], p[(1 << N) + 10];
int tmp[(1 << N) + 10];
bool visval[(1 << N) + 10], vispos[(1 << N) + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    srand(time(0));
    int n = fr(), xsum = 0, tot = 1 << n;
    for (int i = 0; i < (1 << n); i++) fr(a[i]), xsum ^= a[i], arr[i] = i;
    if (xsum) return puts("Fou"), 0;
    puts("Shi");
    for (int i = 0; i < (1 << n); i++) {
        int pos = rand() % tot, arrpos = arr[pos];
        if (pos != tot - 1) arr[pos] = arr[tot - 1];
        tot--, tmp[0] = 0;
        bool flag = 0;
        for (int j = 0; j < (1 << n); j++)
            if (vispos[j] == 0 && visval[arrpos ^ a[j]] == 0) {
                flag = visval[arrpos ^ a[j]] = vispos[j] = 1, ans[j] = arrpos, p[arrpos ^ a[j]] = j;
                break;
            } else if (vispos[j] == 0) tmp[++tmp[0]] = j;
        if (flag == 0) {
            int j = tmp[rand() % tmp[0] + 1];
            vispos[p[arrpos ^ a[j]]] = 0;
            arr[tot++] = ans[p[arrpos ^ a[j]]], ans[j] = arrpos;
            vispos[j] = 1;
            visval[ans[j] ^ a[j]] = 1;
            p[ans[j] ^ a[j]] = j;
            i--;
        }
    }
    for (int i = 0; i < (1 << n); i++) printf("%d ", ans[i] ^ a[i]);
    puts("");
    for (int i = 0; i < (1 << n); i++) printf("%d ", ans[i]);
    puts("");
    return 0;
}