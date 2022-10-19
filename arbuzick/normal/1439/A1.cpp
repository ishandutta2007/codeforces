#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int a[100][100];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = s[i][j]-'0';
            }
        }
        vector<pair<int, int>> q1, q2, q3;
        for (int i = 0; i+2 < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    if (j+1 < m) {
                        q1.pb({i, j});
                        q2.pb({i+1, j});
                        q3.pb({i+1, j+1});
                        a[i][j] ^= 1;
                        a[i+1][j] ^= 1;
                        a[i+1][j+1] ^= 1;
                    } else {
                        q1.pb({i, j});
                        q2.pb({i+1, j});
                        q3.pb({i+1, j-1});
                        a[i][j] ^= 1;
                        a[i+1][j] ^= 1;
                        a[i+1][j-1] ^= 1;
                    }
                }
            }
        }
        for (int j = 0; j+2 < m; ++j) {
            for (int i = n-2; i < n; ++i) {
                if (a[i][j] == 1) {
                    if (i == n-2) {
                        q1.pb({i, j});
                        q2.pb({i, j+1});
                        q3.pb({i+1, j+1});
                        a[i][j] ^= 1;
                        a[i][j+1] ^= 1;
                        a[i+1][j+1] ^= 1;
                    } else {
                        q1.pb({i, j});
                        q2.pb({i, j+1});
                        q3.pb({i-1, j+1});
                        a[i][j] ^= 1;
                        a[i][j+1] ^= 1;
                        a[i-1][j+1] ^= 1;
                    }
                }
            }
        }
        if (a[n-2][m-2]+a[n-1][m-2]+a[n-2][m-1]+a[n-1][m-1] == 4) {
            q1.pb({n-1, m-1});
            q2.pb({n-2, m-1});
            q3.pb({n-1, m-2});
            a[n-1][m-1] = a[n-2][m-1] = a[n-1][m-2] = 0;
        }
        if (a[n-2][m-2]+a[n-1][m-2]+a[n-2][m-1]+a[n-1][m-1] == 1) {
            if (a[n-2][m-2] == 1) {
                q1.pb({n-2, m-2});
                q2.pb({n-1, m-2});
                q3.pb({n-2, m-1});
                a[n-2][m-2] = 0;
                a[n-1][m-2] = a[n-2][m-1] = 1;
            } else if (a[n-2][m-1] == 1) {
                q1.pb({n-2, m-2});
                q2.pb({n-2, m-1});
                q3.pb({n-1, m-1});
                a[n-2][m-1] = 0;
                a[n-2][m-2] = a[n-1][m-1] = 1;
            } else if (a[n-1][m-2] == 1) {
                q1.pb({n-1, m-2});
                q2.pb({n-2, m-2});
                q3.pb({n-1, m-1});
                a[n-1][m-2] = 0;
                a[n-2][m-2] = a[n-1][m-1] = 1;
            } else {
                q1.pb({n-2, m-1});
                q2.pb({n-1, m-2});
                q3.pb({n-1, m-1});
                a[n-1][m-1] = 0;
                a[n-1][m-2] = a[n-2][m-1] = 1;
            }
        }
        if (a[n-2][m-2]+a[n-1][m-2]+a[n-2][m-1]+a[n-1][m-1] == 2) {
            if (a[n-1][m-1] == a[n-2][m-2]) {
                if (a[n-1][m-1] == 0) {
                    q1.pb({n-1, m-1});
                    q2.pb({n-2, m-2});
                    q3.pb({n-1, m-2});
                    a[n-1][m-1] = a[n-2][m-2] = 1;
                    a[n-1][m-2] = 0;
                } else {
                    q1.pb({n-1, m-1});
                    q2.pb({n-2, m-1});
                    q3.pb({n-1, m-2});
                    a[n-1][m-2] = a[n-2][m-1] = 1;
                    a[n-1][m-1] = 0;
                }
            } else {
                if (a[n-1][m-1] == 0 && a[n-1][m-2] == 0) {
                    q1.pb({n-1, m-1});
                    q2.pb({n-2, m-2});
                    q3.pb({n-1, m-2});
                    a[n-1][m-1] = a[n-1][m-2] = 1;
                    a[n-2][m-2] = 0;
                } else  if (a[n-1][m-1] == 0 && a[n-2][m-1] == 0) {
                    q1.pb({n-1, m-1});
                    q2.pb({n-2, m-1});
                    q3.pb({n-2, m-2});
                    a[n-1][m-1] = a[n-2][m-1] = 1;
                    a[n-2][m-2] = 0;
                } else if (a[n-2][m-2] == 0 && a[n-1][m-2] == 0) {
                    q1.pb({n-1, m-1});
                    q2.pb({n-2, m-2});
                    q3.pb({n-1, m-2});
                    a[n-2][m-2] = a[n-1][m-2] = 1;
                    a[n-1][m-1] = 0;
                } else {
                    q1.pb({n-1, m-1});
                    q2.pb({n-2, m-1});
                    q3.pb({n-2, m-2});
                    a[n-2][m-2] = a[n-2][m-1] = 1;
                    a[n-1][m-1] = 0;
                }
            }
        }
        if (a[n-2][m-2]+a[n-1][m-2]+a[n-2][m-1]+a[n-1][m-1] == 3) {
            if (a[n-2][m-2] == 0) {
                q1.pb({n-2, m-1});
                q2.pb({n-1, m-2});
                q3.pb({n-1, m-1});
            } else if (a[n-2][m-1] == 0) {
                q1.pb({n-2, m-2});
                q2.pb({n-1, m-2});
                q3.pb({n-1, m-1});
            } else if (a[n-1][m-2] == 0) {
                q1.pb({n-2, m-1});
                q2.pb({n-2, m-2});
                q3.pb({n-1, m-1});
            } else {
                q1.pb({n-2, m-1});
                q2.pb({n-1, m-2});
                q3.pb({n-2, m-2});
            }
        }
        cout << q1.size() << '\n';
        for (int i = 0; i < q1.size(); ++i) {
            cout << q1[i].f+1 << ' ' << q1[i].s+1 << ' ';
            cout << q2[i].f+1 << ' ' << q2[i].s+1 << ' ';
            cout << q3[i].f+1 << ' ' << q3[i].s+1 << '\n';
        }
    }
    return 0;
}