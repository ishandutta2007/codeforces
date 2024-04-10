#include <bits/stdc++.h>

using namespace std;

const int di[] = {0, 0, 1,-1};
const int dj[] = {1,-1, 0, 0};

int n, m, q, p;
char a[250][250];
int noi[250][250];
int ret;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> q >> p;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(!('A' <= a[i][j] && a[i][j] <= 'Z')) continue;
            queue<int> qi, qj;
            vector<bitset<250>> was(n);
            qi.push(i);
            qj.push(j);
            was[i].set(j);
            for(int k = (a[i][j] - 'A' + 1) * q; k > 0; k /= 2) {
                queue<int> qii, qjj;
                while(!qi.empty()) {
                    int i = qi.front(); qi.pop();
                    int j = qj.front(); qj.pop();
                    noi[i][j] += k;
                    if(k == 1) continue;
                    for(int w = 0; w < 4; w++) {
                        int ii = i + di[w];
                        int jj = j + dj[w];
                        if(0 <= ii && ii < n && 0 <= jj && jj < m && a[ii][jj] != '*' && !was[ii][jj]) {
                            qii.push(ii);
                            qjj.push(jj);
                            was[ii].set(jj);
                        }
                    }
                }
                qi = qii;
                qj = qjj;
            }
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ret += (noi[i][j] > p);
    cout << ret;
}