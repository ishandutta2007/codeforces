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

vector<int> p[256];
int cp[256];

int main() {
    init_cin
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    int m;
    cin >> m;

    while (m-- > 0) {
        int x;
        string ss;
        cin >> x >> ss;
        --x;
        char c = ss[0];
        int i = 0;
        for (; i < p[c].size(); i++) {
            if (p[c][i] <= x) {
                x++;
            } else {
                break;
            }
        }
        p[c].insert(p[c].begin() + i, x);
//        p[c].push_back(x);
//        sort(p[c].begin(), p[c].end());
    }

    for (int i = 0; i < 256; i++) {
        reverse(p[i].begin(), p[i].end());
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            char c = s[j];
            if (!p[c].empty() && p[c].back() == cp[c]) {
                p[c].pop_back();
            } else {
                cout << c;
            }
            cp[c]++;
        }
    }


    return 0;
}