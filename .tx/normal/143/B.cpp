#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    string s;
    cin >> s;
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
        s = s.substr(1, s.size() - 1);
    }
    int p = s.find('.');
    string ip, sp;
    if (p == -1) {
        ip = s;
        sp = "";
    } else {
        ip = s.substr(0, p);
        sp = s.substr(p + 1, sp.size() - p - 1);
    }
    if (neg) {
        cout << "(";
    }
    cout << "$";
    for (int i = 0; i < ip.size(); i++) {
        if (i != 0 && i + 1 != ip.size() && (ip.size() - i) % 3 == 0) {
            cout << ",";
        }
        cout << ip[i];
    }
    cout << ".";
    if (sp.size() > 2) {
        sp = sp.substr(0, 2);
    }
    cout << sp;
    for (int i = sp.size(); i < 2; i++) {
        cout << "0";
    }
    if (neg) {
        cout << ")";
    }

    return 0;
}