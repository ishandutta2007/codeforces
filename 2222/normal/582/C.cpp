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

int gcd(int x, int y) { for (; y; swap(x %= y, y)); return x; }

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    long long res = 0;
    vector<int> h;
    vector<vector<int>> ss(n);
    for (int s = 1; s < n; ++s)
        ss[gcd(s, n)].push_back(s);
    for (int x = 1; x < n; ++x)
        if (n % x == 0) {
            vector<bool> u(n);
            for (int i = 0; i < x; ++i) {
                vector<int> c;
                int mx = 0;
                for (int j = i; j < n; j += x) {
                    if (a[j] > mx) {
                        c.clear();
                        mx = a[j];
                    }
                    if (a[j] >= mx) c.push_back(j);
                }
                for (int j : c) u[j] = true;
            }
            for (int i = 0; i < n; ++i) {
                if (!u[i]) {
                    vector<bool> t(u.begin(), u.begin() + i);
                    u.erase(u.begin(), u.begin() + i);
                    u.insert(u.end(), all(t));
                    break;
                }
            }
            for (int i = 0; i < n; ++i) {
                int k = 0;
                for (; i < n && u[i]; ++i, ++k);
                for (int s : ss[x]) {
                    if (s > k)
                        break;
                    if (k < n) {
                        res += k - s + 1;
                    } else {
                        res += n;
                    }
                }
            }
        }
    cout << res << endl;
    return 0;
}