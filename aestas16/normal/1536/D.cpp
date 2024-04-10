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

int n, arr[N + 10];

struct Node {
    int val, id;
    bool operator < (const Node &rhs) const {
        if (val == rhs.val) return id < rhs.id;
        return val < rhs.val;
    }
} a[N + 10];

namespace BIT {
    int c[N + 10];
    int lowbit(int x) { return x & -x; }
    void update(int pos) {
        for (int i = pos; i <= n; i += lowbit(i)) c[i]++;
    }
    int qsum(int pos) {
        int ret = 0;
        for (int i = pos; i; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    bool check(int i) {
        if (arr[i] < arr[i - 1] && qsum(arr[i]) != qsum(arr[i - 1] - 1)) return true;
        if (arr[i - 1] < arr[i] && qsum(arr[i] - 1) != qsum(arr[i - 1])) return true;
        return false;
    }
} // namespace BIT
using namespace BIT;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        n = fr();
        for (int i = 1; i <= n; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) fr(a[i].val), a[i].id = i;
        sort(a + 1, a + 1 + n), a[0].val = -2e9;
        for (int i = 1, tot = 0; i <= n; i++) {
            if (a[i].val > a[i - 1].val) tot++;
            arr[a[i].id] = tot;
        }
        for (int i = 1; i <= n; i++) {
            update(arr[i]);
            if (i == 1) continue;
            if (check(i)) {
                puts("NO");
                goto cat;
            }
        }
        puts("YES");
        cat:;
    }
    return 0;
}