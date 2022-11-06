#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

const int M = 256 * 256;
vector<int> g[M];
vector<int> ans;

void euler(int v) {
    while (g[v].size() > 0) {
        int to = g[v].back();
        g[v].pop_back();
        euler(to);
    }
    ans.push_back(v);
}

int kin[M];
int kout[M];

int main() {
    scid(n);
    char s[4];
    int no = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        int x = s[0] * 256 + s[1];
        int y = s[1] * 256 + s[2];
        g[x].push_back(y);
        kin[y]++;
        kout[x]++;
        no = x;
    }
    int ko = 0;
    for (int i = 0; i < M; i++) {
        if (kin[i] != kout[i]) {
            if (abs(kin[i] - kout[i]) > 1) {
                cout << "NO";
                return 0;
            }
            ko++;
            if (kout[i] > kin[i]) {
                no = i;
            }
        }
    }
    if (ko > 2) {
        cout << "NO";
        return 0;
    }
    euler(no);
    if (ans.size() != n + 1) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) {
        int x = ans[n - i];
        if (i == 0) {
            printf("%c", x / 256);
        }
        printf("%c", x % 256);
    }

    return 0;
}