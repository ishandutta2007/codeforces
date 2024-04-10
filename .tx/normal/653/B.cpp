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

string a[44];
string b[44];

map<string, string> m;

char s[11];

int main() {
    init_cin
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i];
        m[a[i]] = b[i];
    }
    int cc = 1;
    for (int i = 0; i < n; i++) {
        s[i] = 'a';
        cc *= 6;
    }

    int ans = 0;

    while (s[n] == 0) {
        string x;
        x += s[0];
        bool ok = true;
        for (int i = 1; i < n; i++) {
            x += s[i];
            if (m.find(x) == m.end()) {
                ok = false;
                break;
            }
            x = m[x];
        }
        if (x == "a") {
            ans++;
        }

        s[0]++;

        for (int i = 0; i < 6; i++) {
            if (s[i] > 'f') {
                s[i] = 'a';
                s[i + 1]++;
            }
        }
    }

    cout << ans;


    return 0;
}