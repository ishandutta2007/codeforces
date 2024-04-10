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

vector<pair<int, string> > a[11111];

int main() {
    init_cin
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        int x, b;
        cin >> s >> x >> b;
        --x;
        a[x].push_back({b, s});
    }

    for (int i = 0; i < m; i++) {
        sort(a[i].rbegin(), a[i].rend());
        if (a[i].size() > 2 && a[i][2].first == a[i][1].first) {
            cout << "?";
        } else {
            cout << a[i][0].second << " " << a[i][1].second;
        }
        cout << "\n";
    }

    return 0;
}