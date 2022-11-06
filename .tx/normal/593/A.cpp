#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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
    int n;
    cin >> n;
    vector<string> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i].length();
    }
    int ans = 0;
    for (char x = 'a'; x <= 'z'; x++) {
        for (char y = x + 1; y <= 'z'; y++) {
            int cur = sum;
            for (auto &s : a) {
                for (auto &i : s) {
                    if (i != x && i != y) {
                        cur -= s.length();
                        break;
                    }
                }
            }
            ans = max(ans, cur);
        }
    }
    cout << ans;
    return 0;
}