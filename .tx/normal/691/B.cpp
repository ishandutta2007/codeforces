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

bool ok[256][256];

void mt(char a, char b) {
    ok[a][b] = ok[b][a] = true;
}

int main() {
    string okc = "AHIMOoTUVvWwXxY";
    for (char c : okc) {
        ok[c][c] = true;
    }

    mt('b', 'd');
    mt('p', 'q');

    string s;
    cin >> s;
    for (int i = 0, len = s.length(); i * 2 < len; i++) {
        if (!ok[s[i]][s[len - 1 - i]]) {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK";


    return 0;
}