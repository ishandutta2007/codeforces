#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

vector<int> divs[2 * MAXN];
int par[MAXN];

void solve() {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= 2 * r; i++)
        divs[i].clear();
    for (int i = l; i <= r; i++)
        for (int j = i; j <= 2 * r; j += i)
            divs[j].push_back(i);
    long long answer = 1LL * (r - l + 1) * (r - l) * (r - l - 1) / 6;
    for (int k = l; k <= r; k++)
        if (divs[k].size() >= 3)
            answer -= 1LL * (divs[k].size() - 1) * (divs[k].size() - 2) / 2;
    for (int k = l; k <= r; k++) {
        int sz = divs[2 * k].size();
        for (int i = 0; i < sz; i++) {
            bool good = (lcm(k, divs[2 * k][i]) == 2 * k);
            par[i + 1] = par[i] + good;
        }
        for (int j = 1; j < sz; j++) {
            if (divs[2 * k][j] >= k)
                break;
            int minI = upper_bound(divs[2 * k].begin(), divs[2 * k].end(), k - divs[2 * k][j]) - divs[2 * k].begin();
            if (minI >= j)
                continue;
            int tmp = 0;
            if (lcm(k, divs[2 * k][j]) == 2 * k)
                tmp = j - minI;
            else
                tmp = par[j] - par[minI];
            answer -= tmp;
        }
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}