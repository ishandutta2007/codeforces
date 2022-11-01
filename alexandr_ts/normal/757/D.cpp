#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 77;
const int M = 20;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

int num[N][N];
int d[N][(1 << M)];

void buildNum(string s) {
    int n = s.size();
    fr(i, n + 1)
        fill(num[i], num[i] + n + 1, -1);
    fr(i, n + 1)
        frab(j, i + 1, n + 1) {
            string s2 = s.substr(i, j - i);
            reverse(s2.begin(), s2.end());
            int ans = 0;
            bool er = false;
            fr(i1, s2.size())
                if (s2[i1] == '1')
                    if (i1 < M + 2)
                        ans += (1 << i1);
                    else {
                        er = true;
                        break;
                    }
            if (er)
                ans = 0;
            num[i][j] = ans - 1; ///-1!!!
        }
}

bool badMask(int mask) {
    bool fnd1 = false;
    for (int i = M - 1; i >= 0; i--)
        if (mask & (1 << i))
            fnd1 = true;
        else if (fnd1)
            return true;
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    string s;
    cin >> n;
    cin >> s;
    buildNum(s);

    ///Base
    fr(i, n + 1)
        frab(j, i + 1, n + 1) {
            if (num[i][j] != -1 && num[i][j] < M) {
                //cout << num[i][j] << endl;
                d[j][(1 << num[i][j])]++;
                //cout << j << " " << num[i][j] << endl;
            }
        }

    fr(i, n + 1)
        fr(mask, (1 << M)) {
            if (!d[i][mask])
                continue;
            for (int j = i + 1; j < n + 1 && num[i][j] < M; j++)
            //frab(j, i + 1, n + 1)
                if (num[i][j] != -1) {
                    d[j][mask | (1 << num[i][j])] =
                        (d[j][mask | (1 << num[i][j])] + d[i][mask]);
                    if (d[j][mask | (1 << num[i][j])] >= MOD)
                        d[j][mask | (1 << num[i][j])] -= MOD;
                }
        }

    ll ans = 0;
    fr(i, n + 1)
        fr(mask, (1 << M)) {
            if (!d[i][mask])
                continue;
            if (badMask(mask))
                continue;
            ans = (ans + d[i][mask]);
            if (ans >= MOD)
                ans -= MOD;
        }
    cout << ans;
}