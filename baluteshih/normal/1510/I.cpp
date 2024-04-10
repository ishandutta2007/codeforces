#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int win[1005];
double weight[1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    const double beta = 3. / 4.;
    mt19937 rng(880301);
    for (int i = 1; i <= m; ++i) {
        string s;
        cin >> s;
        int mi = i;
        for (int j = 1; j <= n; ++j)
            mi = min(mi, i - 1 - win[j]);
        for (int j = 1; j <= n; ++j)
            weight[j] = pow(beta, i - 1 - win[j]);
        double sum = 0;
        for (int j = 1; j <= n; ++j)
            sum += weight[j];
        uniform_real_distribution<double> dis(0, sum);
        double nxt = dis(rng);
        for (int j = 1; j <= n; ++j)
            if (nxt <= weight[j]) {
                cout << s[j - 1] << endl;
                break;
            }
            else
                nxt -= weight[j];
        char res;
        cin >> res;
        for (int j = 1; j <= n; ++j)
            if (s[j - 1] == res)
                ++win[j];
    }
}