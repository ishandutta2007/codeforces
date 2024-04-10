#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

bool vasya(int xp, int yp, int xv, int yv) {
    for (; ; ) {
        if (xp + yp == 0)
            return false;
        if (xv + yv == 0)
            return true;
        if (xp < yp) {
            swap(xp, yp);
            swap(xv, yv);
        }
        if (xp <= xv && yp <= yv)
            return false;
        if (xv + yv < xp + yp)
            return true;
        if (xp + yp < max(xv, yv))
            return false;
        if (yp == 0 && yv == 0)
            return xv < xp;
        if (xp == xv && yp > 0)
            --yp;
        else if (yp == yv && xp > 0)
            --xp;
        else
            --(xp > yp ? xp : yp);
        if (xv > 0)
            --xv;
        if (yv > 0)
            --yv;
    }
}

int main() {
    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;
    cout << (vasya(xp, yp, xv, yv) ? "Vasiliy" : "Polycarp") << endl;
    return 0;
}