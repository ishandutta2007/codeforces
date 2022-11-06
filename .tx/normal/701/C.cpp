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
int cnt[256];


int main() {
    scid(n);
    scanf("\n%s", s);
    set<char> st;
    for (int i = 0; i < n; i++) {
        st.insert(s[i]);
    }
    int all = st.size();
    int cur = 0;
    int ans = n;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[s[i]] == 0) {
            cur++;
        }
        cnt[s[i]]++;
        while (cnt[s[l]] > 1) {
            cnt[s[l]]--;
            l++;
        }
        if (cur == all) {
            ans = min(ans, i - l + 1);
        }
    }

    cout << ans;



    return 0;
}