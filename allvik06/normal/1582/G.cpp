#include <iostream>
#include <vector>
#include <set>

using namespace std;
const int MAXN = 1e6 + 10;

inline void solve() {
    int n;
    cin >> n;
    vector <int> mind(MAXN), p;
    for (int i = 2; i < MAXN; ++i) {
        if (mind[i] == 0) {
            mind[i] = i;
            p.push_back(i);
        }
        for (int j : p) {
            if (i * j >= MAXN || j > mind[i]) break;
            mind[i * j] = j;
        }
    }
    vector <vector <pair <int, int>>> flex(MAXN);
    string b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (x > 1) {
            int d = mind[x], c = 0;
            while (x % d == 0) {
                x /= d;
                c++;
            }
            flex[d].emplace_back(i, c);
        }
    }
    cin >> b;
    vector <vector <int>> open(n), close(n + 1);
    for (int i = 2; i < MAXN; ++i) {
        int l = (int)flex[i].size();
        vector <int> psum(l + 1);
        for (int j = 0; j < l; ++j) {
            psum[j + 1] = psum[j];
            if (b[flex[i][j].first] == '*') psum[j + 1] += flex[i][j].second;
            else psum[j + 1] -= flex[i][j].second;
        }
        vector <int> bl_less(l + 1, -1), st;
        for (int j = 0; j <= l; ++j) {
            while (!st.empty() && psum[j] < psum[st.back()]) {
                bl_less[st.back()] = j;
                st.pop_back();
            }
            st.push_back(j);
        }
        for (int j = 0; j < l; ++j) {
            if (bl_less[j] != -1) {
                int ll = 0, rr = flex[i][j].first + 1;
                if (j) ll = flex[i][j - 1].first + 1;
                open[ll].push_back(flex[i][bl_less[j] - 1].first);
                close[rr].push_back(flex[i][bl_less[j] - 1].first);
            }
        }
    }
    long long ans = 0;
    multiset <int> now;
    for (int i = 0; i < n; ++i) {
        for (int j : open[i]) now.insert(j);
        for (int j : close[i]) now.erase(now.find(j));
        if (now.empty()) ans += n - i;
        else ans += *now.begin() - i;
    }
    cout << ans;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*
 9
8
12
8
5
0
0

1 5 -> 1
2 4 -> 2
3 3 -> 3
4 2 -> 2
5 1 -> 1
 */