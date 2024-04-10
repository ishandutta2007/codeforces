using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <ctime>

typedef long long ll;


int main() {
    int n;
    cin >> n;
    vector < pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ns=0;
        int bs = 0;
        for (char c : s) {
            if (c == 'B') bs++;
            else ns++;
        }
        v.push_back({ bs, ns });
    }
    int lo = -1;
    int hi = 1000000;
    while (hi - lo > 1) {
        int md = (hi + lo) / 2;
        int minbs = 0;
        int minns = 0;
        int maxbs = 1000000;
        int maxns = 1000000;
        int minnmb = -1000000;
        int maxnmb = 1000000;
        for (auto p : v) {
            minbs = max(minbs, p.first - md);
            minns = max(minns, p.second - md);
            maxbs = min(maxbs, p.first + md);
            maxns = min(maxns, p.second + md);
            minnmb = max(minnmb, p.second - p.first - md);
            maxnmb = min(maxnmb, p.second - p.first + md);
        }
        if (minns - maxbs > maxnmb) {
            lo = md;
            continue;
        }
        if (maxns - minbs < minnmb) {
            lo = md;
            continue;
        }
        if (minns > maxns || minbs > maxbs || minnmb > maxnmb) {
            lo = md;
            continue;
        }
        if (0 >= minns && 0 <= maxns && 0 >= minbs && 0<=maxbs && 0 >= minnmb && 0 <= maxnmb) {
            if (1 >= minns && 1 <= maxns && 0 >= minbs && 0 <= maxbs && 1 >= minnmb && 1 <= maxnmb) {
                hi = md;
                continue;
            }
            if (0 >= minns && 0 <= maxns && 1 >= minbs && 1 <= maxbs && -1 >= minnmb && -1 <= maxnmb) {
                hi = md;
                continue;
            }
            if (1 >= minns && 1 <= maxns && 1 >= minbs && 1 <= maxbs && 0 >= minnmb && 0 <= maxnmb) {
                hi = md;
                continue;
            }
            lo = md;
            continue;
        }
        hi = md;
        continue;
    }
    cout << hi << endl;
    int minbs = 0;
    int minns = 0;
    int maxbs = 1000000;
    int maxns = 1000000;
    int minnmb = -1000000;
    int maxnmb = 1000000;
    for (auto p : v) {
        minbs = max(minbs, p.first - hi);
        minns = max(minns, p.second - hi);
        maxbs = min(maxbs, p.first + hi);
        maxns = min(maxns, p.second + hi);
        minnmb = max(minnmb, p.second - p.first - hi);
        maxnmb = min(maxnmb, p.second - p.first + hi);
    }
    int ns, bs;
    bs = minbs;
    for (ns = minns; ns <= maxns; ns++) {
        if (ns == 0 && bs == 0) continue;
        if (ns >= minns && ns <= maxns && bs >= minbs && bs <= maxbs && ns - bs >= minnmb && ns - bs <= maxnmb) {
            for (int i = 0; i < bs; i++) cout << "B";
            for (int i = 0; i < ns; i++) cout << "N";
            return 0;
        }
    }
    bs = maxbs;
    for (ns = minns; ns <= maxns; ns++) {
        if (ns == 0 && bs == 0) continue;
        if (ns >= minns && ns <= maxns && bs >= minbs && bs <= maxbs && ns - bs >= minnmb && ns - bs <= maxnmb) {
            for (int i = 0; i < bs; i++) cout << "B";
            for (int i = 0; i < ns; i++) cout << "N";
            return 0;
        }
    }
    ns = minns;
    for (bs = minbs; bs <= maxbs; bs++) {
        if (ns == 0 && bs == 0) continue;
        if (ns >= minns && ns <= maxns && bs >= minbs && bs <= maxbs && ns - bs >= minnmb && ns - bs <= maxnmb) {
            for (int i = 0; i < bs; i++) cout << "B";
            for (int i = 0; i < ns; i++) cout << "N";
            return 0;
        }
    }
    ns = maxns;
    for (bs = minbs; bs <= maxbs; bs++) {
        if (ns == 0 && bs == 0) continue;
        if (ns >= minns && ns <= maxns && bs >= minbs && bs <= maxbs && ns - bs >= minnmb && ns - bs <= maxnmb) {
            for (int i = 0; i < bs; i++) cout << "B";
            for (int i = 0; i < ns; i++) cout << "N";
            return 0;
        }
    }

}