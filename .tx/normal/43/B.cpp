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

int k1[256], k2[256];

int main() {
    init_cin();
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
//    cerr << s1 << endl << s2 << endl;
    for (auto c : s1) {
        if (c != ' ') {
            k1[c]++;
        }
    }
    for (auto c : s2) {
        if (c != ' ') {
            k2[c]++;
        }
    }
    for (int i = 0; i < 256; i++) {
        if (k1[i] < k2[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";


    return 0;
}