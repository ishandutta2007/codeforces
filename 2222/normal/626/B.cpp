#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int F[222][222][222];

int f(int r, int g, int b) {
    if (r < 0 || g < 0 || b < 0)
        return 0;
    if (r + g + b == 1)
        return r + g * 2 + b * 4;
    int &res = F[r][g][b];
    if (res < 0) {
        res = 0;
        if (r >= 2) res |= f(r - 1, g, b);
        if (g >= 2) res |= f(r, g - 1, b);
        if (b >= 2) res |= f(r, g, b - 1);
        res |= f(r - 1, g - 1, b + 1);
        res |= f(r - 1, g + 1, b - 1);
        res |= f(r + 1, g - 1, b - 1);
    }
    return res;
}

int main() {
    CL(F, -1);
    int n;
    string s;
    cin >> n >> s;
    int mask = f(count(all(s), 'R'), count(all(s), 'G'), count(all(s), 'B'));
    string res;
    REP (i, 3) {
        if (mask & 1 << i)
            res += "RGB"[i];
    }
    sort(all(res));
    cout << res << endl;
    return 0;
}