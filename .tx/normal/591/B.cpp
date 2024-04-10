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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    init_cin();
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    char a[256];
    int p[256];
    for (char i = 'a'; i <= 'z'; i++) {
        a[i] = i;
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        char c = s1[0];
        char d = s2[0];
        swap(a[p[c]], a[p[d]]);
        swap(p[c], p[d]);
    }
    for (int i = 0; i < s.length(); i++) {
        cout << a[s[i]];
    }

    return 0;
}