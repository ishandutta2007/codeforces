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

string repl[256];

string readTrans() {
    string s;
    cin >> s;
    string res = "";
    for (char c : s) {
        res += repl[c];
    }
    return res;
}

string a[3];

int main() {
    init_cin
    for (char i = 'a'; i <= 'z'; i++) {
        repl[i] = i;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        repl[i] = (char) (i - 'A' + 'a');
    }

    a[0] = readTrans();
    a[1] = readTrans();
    a[2] = readTrans();

    int p[3] = {0, 1, 2};
    string ok[6];
    int x = 0;
    do {
        ok[x++] = a[p[0]] + a[p[1]] + a[p[2]];
    } while (next_permutation(p, p + 3));

    int n;
    cin >> n;
    while (n-- > 0) {
        string s = readTrans();
        bool acc = false;
        for (int i = 0; i < 6; i++) {
            if (s == ok[i]) {
                acc = true;
                break;
            }
        }
        cout << (acc ? "ACC" : "WA") << "\n";
    }

    return 0;
}