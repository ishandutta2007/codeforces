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

char s[111111];
int p[111111];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    stack<pair<char, int> > st;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            st.push({s[i], i});
        } else if (!st.empty()) {
            auto v = st.top();
            char c = v.first;
            if (s[i] == ')' && c == '(' || s[i] == ']' && c == '[') {
                p[i] = v.second;
                p[v.second] = i;
                st.pop();
            } else {
                while (!st.empty()) {
                    st.pop();
                }
            }
        }
    }
    int ans = 0;
    int l = 0, r = -1;
    int i = 0;
    while (i < n) {
        while (i < n && p[i] == -1) {
            i++;
        }
        if (i == n) {
            break;
        }
        int cl = i;
        while (p[i] + 1 < n && p[p[i] + 1] != -1) {
            i = p[i] + 1;
        }
        int cr = p[i];
        int co = 0;
        for (int i = cl; i <= cr; i++) {
            if (s[i] == '[') {
                co++;
            }
        }
        if (co > ans) {
            ans = co;
            l = cl;
            r = cr;
        }
        i = p[i] + 1;
    }

    cout << ans << "\n";
    for (int i = l; i <= r; i++) {
        cout << s[i];
    }

    return 0;
}