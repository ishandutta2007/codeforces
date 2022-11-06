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

string s[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

int pos(string& a) {
    for (int i = 0; i < 12; i++) {
        if (s[i] == a) {
            return i;
        }
    }
    return -1;
}

bool isMajor(string& a, string& b, string& c) {
    int pa = pos(a);
    int pb = pos(b);
    int pc = pos(c);
    return (pa + 4) % 12 == pb && (pb + 3) % 12 == pc;
}

bool isMinor(string& a, string& b, string& c) {
    int pa = pos(a);
    int pb = pos(b);
    int pc = pos(c);
    return (pa + 3) % 12 == pb && (pb + 4) % 12 == pc;
}


int main() {
    string a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a, a + 3);
    bool mn = false, mj = false;
    do {
        mj |= isMajor(a[0], a[1], a[2]);
        mn |= isMinor(a[0], a[1], a[2]);
    } while (next_permutation(a, a + 3));

    if (mn) {
        cout << "minor";
    } else if (mj) {
        cout << "major";
    } else {
        cout << "strange";
    }

    return 0;
}