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
 
const int N = 5e5;
 
int n, minus, l[N + 10], r[N + 10], a[N + 10], cnt[N + 10], smax[N + 10], f[N + 10];
 
struct Node {
    int l, cnt;
};
 
vector<Node> qwq[N + 10];
 
int cmin(int a, int b) { return a < b ? a : b; }
int cmax(int a, int b) { return a > b ? a : b; }
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    fr(n);
    for (int i = 1; i <= n; i++) l[i] = N + 10;
    for (int i = 1; i <= n; i++) fr(a[i]), l[a[i]] = cmin(l[a[i]], i), r[a[i]] = cmax(r[a[i]], i);
    for (int i = n; i; i--) cnt[a[i]]++, smax[i] = cmax(smax[i + 1], cnt[a[i]]);
    for (int i = 1; i <= n; i++)
        if (cnt[i]) qwq[r[i]].push_back({l[i], cnt[i]});
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < qwq[i].size(); j++) f[i] = cmax(f[i], f[qwq[i][j].l - 1] + qwq[i][j].cnt);
        f[i] = cmax(f[i], f[i - 1]), minus = cmax(minus, f[i] + smax[i + 1]);
    }
    printf("%d\n", n - minus);
    return 0;
}