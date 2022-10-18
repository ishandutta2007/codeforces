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

const int N = 1e5;

int n, atot, z[N + 10], ans[N + 10];
char str[N + 10];

struct Answer {
    int id, cnt;
    bool operator<(const Answer &rhs) const {
        if (id == rhs.id) return cnt < rhs.cnt;
        return id < rhs.id;
    }
} Ans[N + 10];

void Z_Algorithm() {
    z[1] = n;
    for (int i = 2, l = 0, r = 0; i <= n; i++) {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= n && str[i + z[i]] == str[z[i] + 1]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}

struct OI {
    int RP, score;
} FJOI2021;

int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    scanf("%s", str + 1), n = strlen(str + 1), Z_Algorithm();
    for (int i = 1; i <= n; i++) ans[z[i]]++;
    for (int i = n - 1; i; i--) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; i++)
        if (i + z[i] - 1 == n) Ans[++atot] = {z[i], ans[z[i]]};
    sort(Ans + 1, Ans + 1 + atot), printf("%d\n", atot);
    for (int i = 1; i <= atot; i++) printf("%d %d\n", Ans[i].id, Ans[i].cnt);
    return 0;
}