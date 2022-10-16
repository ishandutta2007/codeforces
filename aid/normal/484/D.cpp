#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int a[MAXN];
long long dp[MAXN];
vector< pair<pair<int, int>, long long> > vmin, vmax;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int lmin = i, lmax = i;
        while(!vmin.empty() && a[vmin.back().first.first] >= a[i]) {
            int p = vmin.back().first.second;
            if((lmax? dp[lmax - 1] : 0) + a[lmax] < (p? dp[p - 1] : 0) + a[p])
                lmax = p;
            vmin.pop_back();
        }
        while(!vmax.empty() && a[vmax.back().first.first] <= a[i]) {
            int p = vmax.back().first.second;
            if((lmin? dp[lmin - 1] : 0) - a[lmin] < (p? dp[p - 1] : 0) - a[p])
                lmin = p;
            vmax.pop_back();
        }
        long long ansmin = (vmin.empty()? 0 : vmin.back().second),
            ansmax = (vmax.empty()? 0 : vmax.back().second);
        vmin.push_back(make_pair(make_pair(i, lmax),
                                 max(ansmin, (lmax? dp[lmax - 1] : 0) +
                                     a[lmax] - a[i])));
        vmax.push_back(make_pair(make_pair(i, lmin),
                                 max(ansmax, (lmin? dp[lmin - 1] : 0) +
                                     a[i] - a[lmin])));
        dp[i] = max(vmin.back().second, vmax.back().second);
    }
    cout << dp[n - 1] << '\n';
    return 0;
}