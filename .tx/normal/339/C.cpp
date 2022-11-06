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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

vector<int> ans;

bool used[22][11][1111];
string s;

void dfs(int b, int last, int i) {
    if (i == 0) {
        cout << "YES\n";
        for (auto t = ans.begin(); t != ans.end(); ++t) {
            cout << *t << " ";
        }
        exit(0);
    }
    used[b][last][i] = true;
    for (int t = 0; t < 10; t++) {
        if (s[t] == '0') {
            continue;
        }
        int cur = t + 1;
        if (cur == last) {
            continue;
        }
        int nb = (i % 2 == 0 ? (b + cur) : (b - cur));
        if (nb < 0 || nb > 20 || nb == 10 || ((b != 10) && (nb > 10) == (b > 10))) {
            continue;
        }
        if (!used[nb][cur][i - 1]) {
            ans.push_back(cur);
            dfs(nb, cur, i - 1);
            ans.pop_back();
        }
    }
}


int main() {
    init_cin();
    cin >> s;
    int m;
    cin >> m;
    dfs(10, 0, m);
    cout << "NO";
    return 0;
}