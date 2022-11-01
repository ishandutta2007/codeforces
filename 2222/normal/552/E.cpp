#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll uint64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

string s;

vector<pair<ll, ll>> computePref(int start = 1) {
    vector<pair<ll, ll>> res(1);
    ll a0 = 0, b0 = 0;
    if (s[start - 1] == '*') b0 = 1;
    for (int i = start; i < sz(s); i += 2) {
        int d = s[i] - '0';
        switch (s[i - 1]) {
            case '+':
                a0 += b0;
                b0 = d;
                break;
            case '*':
                b0 *= d;
                break;
        }
        res.emplace_back(a0, b0);
    }
    return res;
}

int main() {
    getline(cin, s);
    s = "+" + s + "+";
    auto pref = computePref();
    reverse(all(s));
    auto suff = computePref();
    reverse(all(s));
    reverse(all(suff));
    ll res = 0;
    for (int i = 1; i < sz(s); i += 2) {
        auto mid = computePref(i);
        FOR (j, 1, sz(mid)) {
            ll a = 0, b = mid[j].X + mid[j].Y;
            switch (s[i - 1]) {
                case '+':
                    a += pref[i / 2].X + pref[i / 2].Y;
                    break;
                case '*':
                    b *= pref[i / 2].Y;
                    a += pref[i / 2].X;
                    break;
            }
            assert(i + j * 2 - 1 < sz(s));
            int k = i / 2 + j;
            assert(k < sz(suff));
            switch (s[i + j * 2 - 1]) {
                case '+':
                    a += suff[k].X + suff[k].Y;
                    break;
                case '*':
                    b *= suff[k].Y;
                    a += suff[k].X;
                    break;
            }
            res = max(res, a + b);
        }
    }
    cout << res << endl;
    return 0;
}