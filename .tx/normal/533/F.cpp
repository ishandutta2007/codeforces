#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

const int inf = 1e9;

vector<int> last(26);

vector<int> lens(string& s) {
    int n = s.length();
    vector<int> a(n);
    last.assign(26, -1);
    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - 'a';
        if (last[c] == -1) {
            a[i] = inf;
        } else {
            a[i] = last[c] - i;
        }
        last[c] = i;
    }
    return a;
}

int main() {
    init_cin
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vector<int> a = lens(s);
    vector<int> b = lens(t);
    b.push_back(-1);
    for (int i : a) {
        b.push_back(i);
    }

    int x = b.size();
    vector<int> z(x);
    int l = 0, r = 0;
    for (int i = 1; i < x; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < x && (b[z[i]] == b[i + z[i]] || (b[z[i]] == inf && z[i] + b[i + z[i]] >= m))) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (z[i + m + 1] == m) {
            vector<int> p(26, -1);
            bool ok = true;
            for (int j = 0; j < 26; j++) {
                if (last[j] == -1) {
                    continue;
                }
                int x = s[i + last[j]] - 'a';
//                if (x != j) {
                    if (p[x] != -1 && p[x] != j || p[j] != -1 && p[j] != x || (p[j] == -1) != (p[x] == -1)) {
                        ok = false;
                        break;
                    }
                    p[x] = j;
                    p[j] = x;
//                }
            }
            if (ok) {
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << " ";
    }


    return 0;
}