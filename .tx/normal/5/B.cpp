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

int main() {
    init_cin
    vector<string> a;
    string s;
    int len = 0;
    while (getline(cin, s)) {
        a.push_back(s);
        len = max(len, (const int &) s.length());
    }
    int ncadd = 0;
    for (int i = 0; i < len + 2; i++) {
        cout << "*";
    }
    cout << "\n";
    for (string& s : a) {
        cout << "*";
        int l = s.length();
        if ((len - l) % 2 == 0) {
            int x = (len - l) / 2;
            for (int i = 0; i < x; i++) {
                cout << " ";
            }
            cout << s;
            for (int i = 0; i < x; i++) {
                cout << " ";
            }
        } else {
            int x = (len - l) / 2;
            for (int i = 0; i < x + ncadd; i++) {
                cout << " ";
            }
            cout << s;
            for (int i = 0; i < x + 1 - ncadd; i++) {
                cout << " ";
            }
            ncadd = 1 - ncadd;
        }

        cout << "*\n";
    }

    for (int i = 0; i < len + 2; ++i) {
        cout << "*";
    }

    return 0;
}