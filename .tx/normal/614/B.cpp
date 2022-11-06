#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

bool isOk(string& s) {
    if (s == "0") {
        return true;
    }
    bool ok = s[0] == '1';
    for (int i = 1; i < s.length(); i++) {
        ok &= s[i] == '0';
    }
    return ok;
}

int main() {
    init_cin
    int n; cin >> n;
    vector<string> a;
    string nok;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (isOk(s)) {
            a.push_back(s);
        } else {
            nok = s;
        }
        if (s == "0") {
            cout << 0;
            return 0;
        }
    }
    if (nok == "") {
        nok = a.back();
        a.pop_back();
    }
    cout << nok;
    for (string& i : a) {
        for (int j = 1; j < i.length(); j++) {
            cout << 0;
        }
    }



    return 0;
}