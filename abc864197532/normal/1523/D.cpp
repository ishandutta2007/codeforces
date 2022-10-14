#include <bits/stdc++.h>
#define all(i) (i).begin(), (i).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl
using namespace std;
template<typename T1, typename T2>
ostream& operator << (ostream &i, pair<T1, T2> j) {
    return i << j.first << ' ' << j.second;
}
template<typename T>
ostream& operator << (ostream &i, vector<T> j) {
    i << '{' << j.size() << ':';
    for (T ii : j) i << ' ' << ii;
    return i << '}';
}
template<typename T>
ostream& operator << (ostream &i, set<T> j) {
    i << '{' << j.size() << ':';
    for (T ii : j) i << ' ' << ii;
    return i << '}';
}
typedef long long ll;
typedef pair<int, int> pi;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) if (s[j] == '1') v[i].push_back(j);
    }
    int cnt[1 << 15], pp[1 << 15], id[m], mx = 0;
    for (int i = 0; i < 1 << 15; ++i) pp[i] = __builtin_popcount(i);
    string ans(m, '0');
    bool vis[n]{};
    for (int _ = 0; _ < min(n, 50); ++_) {
        int i = uniform_int_distribution<int>(0, n - 1)(rng), _id = 0;
        while (vis[i]) i = rand() % n;
        vis[i] = true;
        for (int &j : id) j = -1;
        for (int &j : cnt) j = 0;
        for (int j : v[i]) id[j] = _id++;
        for (int j = 0; j < n; ++j) {
            int tmp = 0;
            for (int ii : v[j]) if (~id[ii])
                    tmp |= 1 << id[ii];
            ++cnt[tmp];
        }
        for (int ii = 0; ii < 15; ++ii) for (int j = 0; j < 1 << 15; ++j) if (cnt[j] && j >> ii & 1) {
                    cnt[j ^ 1 << ii] += cnt[j];
                }
        int _mx = 0, _ans = 0;
        for (int j = 0; j < 1 << 15; ++j) if (cnt[j] >= (n + 1 >> 1) && pp[j] > _mx)
                _mx = pp[j], _ans = j;
        if (_mx > mx) {
            for (int j = 0; j < m; ++j)
                ans[j] = id[j] == -1 ? '0' : _ans >> id[j] & 1 ? '1' : '0';
            mx = _mx;
        }
    }
    cout << ans;
}