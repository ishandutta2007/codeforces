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

pair<int, int> a[3333];
string back[3333];
int ans[3333];

int main() {
    init_cin
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (m.find(s) == m.end()) {
            int t = m.size();
            m[s] = t;
            back[t] = s;
        }
        a[i] = {x, m[s]};
    }

    sort(a, a + n);
    vector<int> p;

    for (int i = 0; i < n; i++) {
        int wh = a[i].second;
        int to = a[i].first;
        if (to > p.size()) {
            cout << -1;
            return 0;
        }
        p.insert(p.begin() + to, wh);
    }

    for (int i = 0; i < n; i++) {
        ans[p[i]] = n - i;
    }

    for (int i = 0; i < n; i++) {
        int wh = a[i].second;
        cout << back[wh] << " " << ans[wh] << "\n";
    }

    return 0;
}