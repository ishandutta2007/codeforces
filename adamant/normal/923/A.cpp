#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

bool notp[1000100];
int mxd[1001000];

int main() {
    vector<int> p;
    for (int i = 2; i <= 1000000; ++i) {
        if (notp[i]) {
            continue;
        }
        p.pb(i);
        for (int j = i + i; j <= 1000000; j += i) {
            notp[j] = true;
            mxd[j] = i;
        }
    }
    int x;
    cin >> x;
    vector<int> px;
    forn (i, p.size()) {
        if (x % p[i] == 0) {
            px.pb(p[i]);
        }
    }
    int res = x;
    for (int x1 = 3; x1 <= x; ++x1) {
        bool was = false;
        forn (i, px.size()) {
            if (x1 > px[i] && x1 > x - px[i]) {
                was = true;
            }
        }
        if (!was) {
            continue;
        }
//        cerr << x1 << endl;
        if (notp[x1]) {
            res = min(res, x1 - mxd[x1] + 1);
        } else {
            res = min(res, x1);
        }
    }
    cout << res << endl;
    return 0;
}