#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN];
long long s[MAXN], add[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        if(i && a[i] != a[i - 1]) {
            g[a[i]].push_back(a[i - 1]);
            s[a[i]] += a[i - 1];
            add[a[i]] += abs(a[i] - a[i - 1]);
            ans += abs(a[i] - a[i - 1]);
        }
        if(i + 1 < m && a[i] != a[i + 1]) {
            g[a[i]].push_back(a[i + 1]);
            s[a[i]] += a[i + 1];
            add[a[i]] += abs(a[i] - a[i + 1]);
        }
    }
    for(int i = 0; i < n; i++)
        sort(g[i].begin(), g[i].end());
    long long ans0 = ans;
    for(int i = 0; i < n; i++) {
        int l = 0, r = g[i].size();
        long long ls = 0, rs = s[i];
        for(size_t j = 0; j < g[i].size(); j++) {
            ans = min(ans, ans0 - add[i] + (long long)l * g[i][j] - ls +
                      rs - (long long)r * g[i][j]);
            l++;
            r--;
            ls += g[i][j];
            rs -= g[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}