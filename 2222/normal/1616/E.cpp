#include <algorithm>
#include <iostream>
#include <cstdint>
#include <cassert>
#include <vector>
#include <string>
#include <deque>
#include <set>

using namespace std;

struct Summator {
    Summator(int n) : f(2 * n), n(n) {}

    void add(int i, int64_t v) {
        for (i += n; i; i /= 2) f[i] += v;
    }

    int64_t sum(int i, int j) {
        int64_t res = 0;
        for (i += n, j += n; i <= j; i = (i + 1) / 2, j = (j - 1) / 2) {
            if (i & 1) res += f[i];
            if (~j & 1) res += f[j];
        }
        return res;
    }

    vector<int64_t> f;
    int n;
};

int64_t solve(string a, string b, int& n) {
    Summator s(n);
    vector<deque<int>> p(26);
    vector<int> f(26), g(26);
    for (int i = 0; i < n; ++i) {
        int x = a[i] - 'a';
        f[x]++;
        p[x].push_back(i);
    }
    int64_t swaps = 0;
    int k = 0, c = 0;
    int64_t res = -1;
    for (; k < n; ++k) {
        int y = b[k] - 'a';
        for (; p[c].empty(); ++c);
        if (c < y) {
            for (int x = 0; x < y; ++x) {
                if (p[x].empty()) continue;
                int i = p[x].front();
                int j = i + s.sum(i, n - 1);
                assert(j >= k);
                int64_t score = swaps + (j - k);
                if (res < 0 || score < res) res = score;
            }
        }
        if (p[y].empty()) break;
        int i = p[y].front();
        p[y].pop_front();
        int j = i + s.sum(i, n - 1);
        assert(j >= k);
        swaps += j - k;
        s.add(i, 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc;
    for (cin >> tc; tc --> 0; ) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        assert(a.size() == n && b.size() == n);
        cout << solve(a, b, n) << endl;
    }
    return 0;
}