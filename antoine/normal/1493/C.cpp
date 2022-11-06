#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, k;
string s;

bool fs() {
    map<char, int> occ;

    for (int i = 0; i < n; ++i)
        ++occ[s[i]];
    for (auto e : occ)
        if (e.second % k)
            return false;
    return true;
}

bool f(const int len) {
    map<char, int> occ;

    for (int i = 0; i < len; ++i)
        ++occ[s[i]];

    for (auto it = occ.begin(); it != occ.end();) {
        it->second = (-it->second % k + k) % k;
        if (!it->second)
            it = occ.erase(it);
        else
            ++it;
    }
    int sum = 0;
    for (auto e : occ)
        sum += e.second;

    if (sum + len > n)
        return false;
    if (n - sum - len > 0)
        occ['z'] += n - sum - len;

    for (int i = len; i < n; ++i) {
        assert(!occ.empty());
        auto it = prev(occ.end());
        assert(it->second > 0);
        if (s[i] > it->first)
            return false;
        if (s[i] < it->first)
            return true;
        it->second--;
        if (!it->second)
            occ.erase(it);
    }
    assert(occ.empty());
    return false;
}

string g(const int len) {
    assert(len < n && s[len] < 'z');

    map<char, int> occ;

    for (int i = 0; i < len; ++i)
        ++occ[s[i]];


    for (auto it = occ.begin(); it != occ.end();) {
        it->second = (-it->second % k + k) % k;
        if (!it->second)
            it = occ.erase(it);
        else
            ++it;
    }

    int sum = 0;
    for (auto e : occ)
        sum += e.second;
    if (len + sum < n && !occ.count(s[len] + 1))
        occ[s[len] + 1] += k;

    string t = s.substr(0, len);
    {
        auto it = occ.upper_bound(s[len]);
        assert(it != occ.end());
        t += it->first;
        assert(it->second > 0);
        if (--it->second == 0)
            occ.erase(it);
    }

    for (auto e : occ) {
        t += string(e.second, e.first);
        assert(e.second > 0);
    }
    assert(t.size() <= n && t.size() % k == 0);
    t += string(n - t.size(), 'a');
    sort(t.begin() + len + 1, t.end());
    assert(t.size() == n && t > s);
    return t;
}

string f() {
    cin >> n >> k >> s;
    if (n % k)
        return "-1";
    if (fs())
        return s;
    int lo = -1, hi = n;

    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        bool ok = f(mid);
        if (ok)
            lo = mid;
        else
            hi = mid - 1;
    }
    if (lo == -1)
        return "-1";
    return g(lo);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        auto res = f();
        cout << res << '\n';
    }
    return 0;
}