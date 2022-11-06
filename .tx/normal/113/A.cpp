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

bool endsWith(string &s, string end) {
    if (s.size() < end.size()) {
        return false;
    }
    for (int i = 0; i < end.size(); i++) {
        if (s[s.size() - 1 - i] != end[end.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool startsWith(string &s, string start) {
    if (s.size() < start.size()) {
        return false;
    }
    for (int i = 0; i < start.size(); i++) {
        if (s[i] != start[i]) {
            return false;
        }
    }
    return true;
}

bool isAdj(string &s) {
    return endsWith(s, "lios") || endsWith(s, "liala");
}

bool isNoun(string &s) {
    return endsWith(s, "etr") || endsWith(s, "etra");
}

bool isVerb(string &s) {
    return endsWith(s, "initis") || endsWith(s, "inites");
}

bool isMan(string &s) {
    return endsWith(s, "lios") || endsWith(s, "etr") || endsWith(s, "initis");
}

bool isWoman(string &s) {
    return endsWith(s, "liala") || endsWith(s, "etra") || endsWith(s, "inites");
}

#define fail cout << "NO"; return 0

#define debmsg(a) if (debug) cout << (a) << endl

int main() {
    bool wasN = false, wasV = false;
    string s;
    init_cin
    int len = 0;
    bool wasM = false, wasW = false;
    bool debug = false;
    while (cin >> s) {
        len++;
        if (len == 1 && startsWith(s, "pertaaskfdjadskfhajsdhasdasdfadsfsdafasdgadfasdfsadfsadffkaasdfkadsgfajsdfhgsdgfjadshasddddddddddddddddddddddddddfjasfffffffffffffffffdkhfjkhasjdffffffffff")) {
            debug = true;
        }
        wasM |= isMan(s);
        wasW |= isWoman(s);
        if (isAdj(s)) {
            if (wasN) {
                debmsg("adj wasN");
                fail;
            }
        } else if (isNoun(s)) {
            if (wasN || wasV) {
                debmsg("noun wasN");
                fail;
            }
            wasN = true;
        } else if (isVerb(s)) {
            wasV = true;
        } else {
            debmsg("not a word");
            fail;
        }
    }
    if (len > 1 && (!wasN || (wasM && wasW))) {
        if (!wasN) {
            debmsg("end !wasN");
        }
        if (wasM && wasW) {
            debmsg("end wasM && wasW");
        }
        fail;
    }
    cout << "YES";//

    return 0;
}