#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
pair<int, int> p[MAXN];
long double rc[MAXN][MAXN], dp[MAXN][MAXN];
int q[MAXN], cnt[MAXN], all[MAXN];
char used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(15);
    int n, m;
    cin >> n >> m;
    int mm = 0;
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int c;
            cin >> c;
            p[mm++] = make_pair(c, i);
        }
        all[i] = k;
    }
    swap(m, mm);
    sort(p, p + m, greater< pair<int, int> >());
    int len = 0;
    for(int i = 0; i < m;) {
        int j = i;
        while(j < m && p[i].first == p[j].first)
            j++;
        if(j - i <= n) {
            for(int k = i; k < j; k++)
                cnt[p[k].second]++;
            n -= j - i;
        }
        else {
            len = j - i;
            for(int k = i; k < j; k++)
                q[k - i] = p[k].second;
            break;
        }
        i = j;
    }
    rc[0][0] = 1;
    for(int i = 1; i < MAXN; i++) {
        rc[i][0] = 1;
        for(int j = 1; j <= i; j++)
            rc[i][j] = rc[i - 1][j - 1] * j / i;
    }
    dp[len][0] = 1;
    for(int i = len - 1; i >= 0; i--)
        for(int j = 0; i + j <= len; j++)
            dp[i][j] = (dp[i + 1][j] * (len - i - j) / (len - i) *
                        rc[all[q[i]]][cnt[q[i]]] +
                        dp[i + 1][j - 1] * j / (len - i) *
                        rc[all[q[i]]][cnt[q[i]] + 1]);
    long double ans = dp[0][n];
    for(int i = 0; i < len; i++)
        used[q[i]] = true;
    for(int i = 0; i < mm; i++)
        if(!used[i])
            ans *= rc[all[i]][cnt[i]];
    cout << ans << '\n';
    return 0;
}