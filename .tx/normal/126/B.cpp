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

int main() {
    init_cin();
    string s;
    getline(cin, s);
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    int max_in = 0;
    for (int i = 1; i + 1 < n; i++) {
        max_in = max(max_in, min(z[i], n - i - 1));
    }

    if (max_in == 0) {
        cout << "Just a legend";
        return 0;
    }
    for (int i = n - max_in; i < n; i++) {
        if (i + z[i] == n) {
            for (int j = 0; j < z[i]; ++j) {
                cout << s[j];
            }
            return 0;
        }
    }
    cout << "Just a legend";

    return 0;
}