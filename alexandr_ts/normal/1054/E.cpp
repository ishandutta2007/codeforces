#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e5 + 10;
const int N = 303;

string s[N][N];
//string stest[N][N];
//int curs[N][N];
//int szs[N][N];
string t[N][N];
char ch[M];

struct Ans {
    int x1, y1, x2, y2;
};

//void check(int n, int m) {
//    fr(i, n)
//        fr(j, m) {
//            stest[i][j] = s[i][j];
//            reverse(stest[i][j].begin(), stest[i][j].end());
//        }
//    int n1;
//    cin >> n1;
//    fr(i, n1) {
//        int x1, y1, x2, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        x1--, y1--, x2--, y2--;
//        stest[x2][y2] = stest[x1][y1].back() + stest[x2][y2];
//        stest[x1][y1].pop_back();
//    }
//    fr(i, n) {
//        fr(j, m)
//            cout << stest[i][j] << " ";cout << endl;}
//}

int main() {
    //freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    fr(i, n)
        fr(j, m) {
            scanf("%s", &ch);
            s[i][j] = ch;
            reverse(s[i][j].begin(), s[i][j].end());
            //szs[i][j] = s[i][j].size();
        }

    fr(i, n)
        fr(j, m) {
            scanf("%s", &ch);
            t[i][j] = ch;
            reverse(t[i][j].begin(), t[i][j].end());
            //cerr << t[i][j] << endl;
        }

//    check(n, m);
//    return 0;

    vector<Ans> ans;
    ans.reserve(4 * M);

    // 1
    for (int j = m - 1; j >= 1; j--) {
        fr(k, s[0][j].size())
            ans.pb({0, j, 0, 0});
        s[0][0] += s[0][j];
        s[0][j].clear();
    }
    // 2
    for (int i = n - 1; i >= 1; i--) {
        fr(k, s[i][0].size())
            ans.pb({i, 0, 0, 0});
        s[0][0] += s[i][0];
        s[i][0].clear();
    }

    // 3
    for (int i = n - 1; i >= 1; i--)
        for (int j = m - 1; j >= 1; j--) {
            for (int k = 0; k < s[i][j].size(); k++) {
                if (s[i][j][k] == '0') {
                    ans.pb({i, j, i, 0});
                    s[i][0] += '0';
                }
                else {
                    ans.pb({i, j, 0, j});
                    s[0][j] += '1';
                }
            }
            //s[i][j].clear();
        }
    // 4
    for (int j = m - 1; j >= 2; j--) {
        fr(k, s[0][j].size()) {
            ans.pb({0, j, 0, 1});
            //s[0][1] += '1';
        }
        //s[0][j].clear();
    }

    // 5
    for (int i = n - 1; i >= 2; i--) {
        fr(k, s[i][0].size()) {
            ans.pb({i, 0, 1, 0});
            //s[1][0] += '0';
        }
        //s[i][0].clear();
    }

    // 6
    fr(i, s[0][0].size()) {
        if (s[0][0][i] == '0') {
            ans.pb({0, 0, 1, 0});
            //s[1][0] += '0';
        } else {
            ans.pb({0, 0, 0, 1});
            //s[0][1] += '1';
        }
    }

    /// make new
    // 1
    for (int i = n - 1; i >= 2; i--) {
        fr(j, t[i][0].size()) {
            if (t[i][0][j] == '0') {
                ans.pb({1, 0, i, 0});
            } else {
                ans.pb({0, 1, i, 1});
                ans.pb({i, 1, i, 0});
            }
        }
    }

    // 2
    for (int j = m - 1; j >= 2; j--) {
        fr(k, t[0][j].size()) {
            if (t[0][j][k] == '1') {
                ans.pb({0, 1, 0, j});
            } else {
                ans.pb({1, 0, 1, j});
                ans.pb({1, j, 0, j});
            }
        }
    }

    // 3
    for (int i = n - 1; i >= 1; i--)
        for (int j = m - 1; j >= 1; j--) {
            fr(k, t[i][j].size()) {
                if (t[i][j][k] == '0') {
                    ans.pb({1, 0, 1, j});
                    if (i != 1)
                        ans.pb({1, j, i, j});
                } else {
                    ans.pb({0, 1, i, 1});
                    if (j != 1)
                        ans.pb({i, 1, i, j});
                }
            }
        }

    // 4
    for (int k = 0; k < t[1][0].size(); k++) {
        if (t[1][0][k] == '0') {
            ans.pb({1, 0, 0, 0});
            ans.pb({0, 0, 1, 0});
        } else {
            ans.pb({0, 1, 0, 0});
            ans.pb({0, 0, 1, 0});
        }
    }

    // 5
    for (int k = 0; k < t[0][1].size(); k++) {
        if (t[0][1][k] == '0') {
            ans.pb({1, 0, 0, 0});
            ans.pb({0, 0, 0, 1});
        } else {
            ans.pb({0, 1, 0, 0});
            ans.pb({0, 0, 0, 1});
        }
    }

    for (int k = 0; k < t[0][0].size(); k++) {
        if (t[0][0][k] == '0') {
            ans.pb({1, 0, 0, 0});
        } else {
            ans.pb({0, 1, 0, 0});
        }
    }

    //cout << ans.size() << "\n";
    printf("%d\n", ans.size());
    for (auto t: ans)
        printf("%d %d %d %d\n", t.x1 + 1, t.y1 + 1, t.x2 + 1, t.y2 + 1);
        //cout << t.x1 + 1 << " " << t.y1 + 1 << " " << t.x2 + 1 << " " << t.y2 + 1 << "\n";
}