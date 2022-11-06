#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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

char s[1111111];

bool isOpen(char c) {
    return c == '(' || c == '[' || c == '{' || c == '<';
}

bool matches(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') || (a == '<' && b == '>');
}

int main() {
    scanf("%s", s);
    stack<char> st;
    int n = strlen(s);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (st.empty() || isOpen(c)) {
            st.push(c);
        } else {
            if (!isOpen(st.top())) {
                puts("Impossible");
                return 0;
            }
            if (!matches(st.top(), c))
                ans++;
            st.pop();
        }
    }

    if (!st.empty()) {
        puts("Impossible");
    } else {
        cout << ans;
    }

    return 0;
}