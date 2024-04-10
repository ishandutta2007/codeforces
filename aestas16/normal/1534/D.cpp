/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 4e3;

int n, tot, a[N + 10];
vector<int> p[N + 10];
vector<pair<int, int> > ans;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), printf("? %d\n", 1), fflush(stdout);
    for (int i = 1; i <= n; i++) {
        fr(a[i]), p[a[i]].push_back(i);
        if (a[i] % 2) tot++;
    }
    if (tot <= (n - 1) / 2) {
        for (int i = 1; i < n; i += 2)
            for (int j = 0; j < p[i].size(); j++) {
                int u = p[i][j];
                printf("? %d\n", u), fflush(stdout);
                for (int k = 1; k <= n; k++) {
                    fr(a[k]);
                    if (a[k] == 1) ans.push_back(make_pair(u, k));
                }
            }
    } else {
        for (int i = 1; i <= n; i++)
            if (a[i] == 1) ans.push_back(make_pair(1, i));
        for (int i = 2; i < n; i += 2)
            for (int j = 0; j < p[i].size(); j++) {
                int u = p[i][j];
                printf("? %d\n", u), fflush(stdout);
                for (int k = 1; k <= n; k++) {
                    fr(a[k]);
                    if (a[k] == 1) ans.push_back(make_pair(u, k));
                }
            }
    }
    printf("!\n");
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
    fflush(stdout);
    return 0;
}