#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;

const ll N = 102;
const ll INF = 2e9 + 10;

string d[N][N][N];
bool ok[N][N][N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();
    ok[0][0][0] = true;
    frab(i, 0, n1 + 1)
        frab(j, 0, n2 + 1)
            frab(k, 0, 1 + n3) {
                if (!ok[i][j][k]) continue;
                if (i < n1 && d[i + 1][j][k].size() < d[i][j][k].size()) {
                    d[i + 1][j][k] = d[i][j][k];

                }
                ok[i + 1][j][k] = true;
                if (j < n2 && d[i][j + 1][k].size() < d[i][j][k].size()) {
                    d[i][j + 1][k] = d[i][j][k];

                }
                ok[i][j + 1][k] = true;
                if (i < n1 && j < n2 && k < n3 && s1[i] == s2[j] && s1[i] == s3[k] && d[i + 1][j + 1][k + 1].size() < d[i][j][k].size() + 1) {
                    d[i + 1][j + 1][k + 1] = d[i][j][k] + s1[i];
                    ok[i + 1][j + 1][k + 1] = true;
                }
                //cout << i << " " << j << " " << k << " " << d[i][j][k] << endl;
                if (i < n1 && j < n2 && s1[i] == s2[j] && k < n3 && s1[i] != s3[k]) {
                    int cur = 0;
                    for (int i1 = max(0, (int)d[i][j][k].size() + 1 - n3); i1 < d[i][j][k].size() + 1; i1++) {
                        int len = (int)d[i][j][k].size() + 1 - i1;
                        if ((d[i][j][k] + s1[i]).substr(i1, len) == s3.substr(0, len)) {
                            cur = len;
                            break;
                        }
                    }
                    //cout << "! " << cur << endl;
                    if (d[i + 1][j + 1][cur].size() < d[i][j][k].size() + 1) {
                        d[i + 1][j + 1][cur] = d[i][j][k] + s1[i];
                        ok[i + 1][j + 1][cur] = true;
                    }
                }
            }
    string ans;
    frab(k, 0, n3)
        if (ans.size() < d[n1][n2][k].size())
            ans = d[n1][n2][k];
    if (ans.size() == 0)
        cout << 0;
    else
    cout << ans;

}