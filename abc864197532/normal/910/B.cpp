#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 3e6;

int dsu[N];
set <int> rt;

void init(int n) {
    for (int i = 0; i < n; ++i) {
        rt.insert(i), dsu[i] = i;
    }
}

int Find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = Find(dsu[x]);
}

void Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return;
    dsu[u] = v;
}

void Union2(int l, int r) {
    vector <int> cur;
    for (auto it = rt.lower_bound(l); it != rt.end() && *it < r; ++it) {
        cur.pb(*it);
    }
    for (int i = 0; i < cur.size(); ++i) {
        if (cur[i] + 1 < r) {
            Union(cur[i], cur[i] + 1), rt.erase(cur[i]);
        }
    }
}



int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> need = {a, a, b, a, a, b};
    int ans = 100;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                for (int ii = 0; ii < 6; ++ii) {
                    for (int jj = 0; jj < 6; ++jj) {
                        for (int kk = 0; kk < 6; ++kk) {
                            int cnt[6]{};
                            cnt[i] += need[0];
                            cnt[j] += need[1];
                            cnt[k] += need[2];
                            cnt[ii] += need[3];
                            cnt[jj] += need[4];
                            cnt[kk] += need[5];
                            bool is = true;
                            int cntt = 0;
                            for (int i = 0; i < 6; ++i) is &= cnt[i] <= n, cntt += cnt[i] != 0;
                            if (is) {
                                ans = min(ans, cntt);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}