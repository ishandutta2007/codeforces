#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> pr;

int sum(int l, int r, int i) {
    return pr[i][r] - pr[i][l];
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> a(n + 1, vector <int> (m));
    pr.resize(n + 1, vector <int> (m + 1));
    forn (i, 0, n)
        forn (j, 0, m) {
            cin >> a[i][j];
            pr[i][j + 1] = pr[i][j] + a[i][j];
        }
    vector <int> dp(m - k + 1), pr(m - k + 1), sf(m - k + 1); 
    forn (i, 0, n) {
        vector <int> new_dp(m - k + 1), new_pr(m - k + 1), new_sf(m - k + 1); 
        forn (j, 0, m - k + 1) {
            new_dp[j] = max(new_dp[j], sum(j, j + k, i) + (j - k - 1 >= 0 ? pr[j - k - 1] : 0));
            new_dp[j] = max(new_dp[j], sum(j, j + k, i) + (j + k < m - k + 1 ? sf[j + k] : 0));
            forn (l, max(0, j - k), j)
                new_dp[j] = max(new_dp[j], dp[l] + sum(l + k, j + k, i));
            forn (l, j, min(j + k, m - k + 1)) 
                new_dp[j] = max(new_dp[j], dp[l] + sum(j, l, i));
            new_dp[j] += sum(j, j + k, i + 1);
        }
        new_pr[0] = new_dp[0];
        forn (j, 1, m - k + 1)
            new_pr[j] = max(new_pr[j - 1], new_dp[j]);
        new_sf[m - k] = new_dp[m - k];
        for (int j = m - k - 1; j >= 0; --j)
            new_sf[j] = max(new_sf[j + 1], new_dp[j]);
        swap(dp, new_dp);
        swap(sf, new_sf);
        swap(pr, new_pr);
    }
    cout << sf[0];
    return 0;
}