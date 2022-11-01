#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int).((a).size())
#define all(a) (a).begin(), (a).end()
const int INF = 1e9, maxn = 5e3;

int n, k, a[4000][4000], dp[800][4000], b[4000][4000], i;
int ptt;
int ql[maxn];
int qr[maxn];
int qpl[maxn];
int qpr[maxn];

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    //scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            //scanf(" %c", &ch);
            a[i][j] = ch - '0';
            if(i) a[i][j] += a[i - 1][j];
            if(j) a[i][j] += a[i][j - 1];
            if(i && j) a[i][j] -= a[i - 1][j - 1];
        }
        for(int j = 0; j <= i; j++)
            b[j][i] = a[i][i] + (j ? -a[j - 1][i] - a[i][j - 1] + a[j - 1][j - 1] : 0);
    }
    for(i = 0; i < k; i++) {
        int pt = ptt;
        ql[ptt] = i;
        qr[ptt] = n - 1;
        qpl[ptt] = i;
        qpr[ptt] = n - 1;
        ptt++;
        int l, r, pl, pr;

        while(pt < ptt) {
            l = ql[pt];
            r = qr[pt];
            pl = qpl[pt];
            pr = qpr[pt];
            pt++;

            int m = (l + r) >> 1, tmp;
            dp[i][m] = INF;
            int pp = -1;
            for(int p = pl; p <= min(pr, m); p++)
                if(!i && p) break;
                else if(dp[i][m] > (tmp = (i && p ? dp[i - 1][p - 1] : 0) + b[p][m]))
                    dp[i][m] = tmp, pp = p;
            if(l <= m - 1) {
                ql[ptt] = l;
                qr[ptt] = m - 1;
                qpl[ptt] = pl;
                qpr[ptt] = pp;
                ptt++;
            }
            if(m + 1 <= r) {
                ql[ptt] = m + 1;
                qr[ptt] = r;
                qpl[ptt] = pp;
                qpr[ptt] = pr;
                ptt++;
            }
        }
    }
    cout << dp[k - 1][n - 1] / 2;
    //printf("%d", dp[k - 1][n - 1] >> 1);
}