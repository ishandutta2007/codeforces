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
#include <locale>

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

struct colon_is_space : std::ctype<char> {
    colon_is_space() : std::ctype<char>(get_table()) {}
    static mask const* get_table()
    {
        static mask rc[table_size];
        rc[':'] = std::ctype_base::space;
        rc[' '] = std::ctype_base::space;
        rc['-'] = std::ctype_base::space;
        rc['\n'] = std::ctype_base::space;
        return &rc[0];
    }
};

int main() {
    init_cin
    cin.imbue(locale(cin.getloc(), new colon_is_space));
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }
    map<string, int> pts;
    map<string, int> goals;
    map<string, int> misses;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        string a, b;
        int x, y;
        cin >> a >> b >> x >> y;
        if (x > y) {
            pts[a] += 3;
        } else if (x < y) {
            pts[b] += 3;
        } else {
            pts[a] += 1;
            pts[b] += 1;
        }
        goals[a] += x;
        goals[b] += y;
        misses[a] += y;
        misses[b] += x;
    }

    sort(names.rbegin(), names.rend(), [pts, goals, misses](const string& a, const string& b) {
        if (pts.find(a)->second != pts.find(b)->second) {
            return pts.find(a)->second < pts.find(b)->second;
        }
        if (goals.find(a)->second - misses.find(a)->second != goals.find(b)->second - misses.find(b)->second) {
            return goals.find(a)->second - misses.find(a)->second < goals.find(b)->second - misses.find(b)->second;
        }
        return goals.find(a)->second < goals.find(b)->second;
    });

    while (names.size() > n / 2) {
        names.pop_back();
    }
    sort(names.begin(), names.end());
    for (auto& i : names) {
        cout << i << "\n";
    }

    return 0;
}