#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

bool forbid[256][256];

int ans = 0;

string s;

bool handled[111111];

void handle(int i, char c1, char c2) {
    int k1 = 0, k2 = 0;
    int j1 = i;
    while (j1 > 0 && (s[j1 - 1] == c1 || s[j1 - 1] == c2)) {
        j1--;
    }
    int j2 = i;
    while (j2 + 1 < s.length() && (s[j2 + 1] == c1 || s[j2 + 1] == c2)) {
        j2++;
    }
    for (int k = j1; k <= j2; k++) {
        if (s[k] == c1) {
            k1++;
        } else {
            k2++;
        }
        handled[k] = true;
    }
    ans += min(k1, k2);
}

int main() {
    init_cin
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        forbid[t[0]][t[1]] = forbid[t[1]][t[0]] = true;
    }

    int last = -1;
    int k1 = 0, k2 = 0;
    char fc1 = 0, fc2 = 0;
    for (int i = 0; i + 1 < s.length(); i++) {
        if (!handled[i] && forbid[s[i]][s[i + 1]]) {
            handle(i, s[i], s[i + 1]);
        }
    }

    cout << ans;
    return 0;
}