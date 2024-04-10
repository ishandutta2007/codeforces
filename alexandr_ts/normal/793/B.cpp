#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 3e5 + 10;
const int M = 1e3 + 10;


char a[M][M];
int dist[M][M];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n, m;
    scanf("%d %d", &n, &m);
    pair <int, int> st, en;
    fr(i, n)
        fr(j, m) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'S')
                st = mp(i, j);
            else if (a[i][j] == 'T')
                en = mp(i, j);
        }

//    fr(i, n) {
//    fr(j, m)cout << a[i][j];cout << endl;}

    fr(i, n)
        fr(j, m)
            dist[i][j] = INF;
    dist[st.first][st.second] = 0;

    queue <pair <int, int> > q;
    q.push(st);


    auto t = q.front();
    q.pop();
    for (int i = 0; i < m; i++)
        if (t.second - i >= 0 && dist[t.first][t.second - i] == INF) {
            if (a[t.first][t.second - i] != '.' && a[t.first][t.second - i] != 'T') break;
            //if (dist[t.first][t.second - i] <= dist[t.first][t.second]) break;
            dist[t.first][t.second - i] = dist[t.first][t.second] + 1;
            //if (dist[t.first][t.second - i] <= 2)
            //    q.push(mp(t.first, t.second - i));
        }

    for (int i = 0; i < m; i++)
        if (t.second + i < m && dist[t.first][t.second + i] == INF) {
            if (a[t.first][t.second + i] != '.' && a[t.first][t.second + i] != 'T') break;
            //if (dist[t.first][t.second + i] <= dist[t.first][t.second]) break;
            dist[t.first][t.second + i] = dist[t.first][t.second] + 1;
            //if (dist[t.first][t.second + i] <= 2)
            //    q.push(mp(t.first, t.second + i));
        }

    for (int i = 0; i < n; i++)
        if (t.first - i >= 0 && dist[t.first - i][t.second] == INF) {
                if (a[t.first - i][t.second] != '.' && a[t.first - i][t.second] != 'T') break;
                //if (dist[t.first - i][t.second] <= dist[t.first][t.second]) break;
            dist[t.first - i][t.second] = dist[t.first][t.second] + 1;
            //if (dist[t.first - i][t.second] <= 2)
             //   q.push(mp(t.first - i, t.second));
        }

    for (int i = 0; i < n; i++)
        if (t.first + i < n && dist[t.first + i][t.second] == INF) {
                if (a[t.first + i][t.second] != '.' && a[t.first + i][t.second] != 'T') break;
                //if (dist[t.first + i][t.second] <= dist[t.first][t.second]) break;
            dist[t.first + i][t.second] = dist[t.first][t.second] + 1;
            //if (dist[t.first + i][t.second] <= 2)
            //    q.push(mp(t.first + i, t.second));
        }

    t = en;

    for (int i = 1; i < m; i++)
        if (t.second - i >= 0) {
            if (a[t.first][t.second - i] != '.' && a[t.first][t.second - i] != 'S') break;
            //if (dist[t.first][t.second - i] <= dist[t.first][t.second]) break;
            //dist[t.first][t.second - i] = dist[t.first][t.second] + 1;
            //if (dist[t.first][t.second - i] <= 2)
            //    q.push(mp(t.first, t.second - i));
            for (int j = 0; j < n; j++) {
                int x1 = t.first - j;
                int y1 = t.second - i;
                if (x1 < 0) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }

            for (int j = 0; j < n; j++) {
                int x1 = t.first + j;
                int y1 = t.second - i;
                if (x1 >= n) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }
        }

    for (int i = 1; i < m; i++)
        if (t.second + i < m) {
            if (a[t.first][t.second + i] != '.' && a[t.first][t.second + i] != 'S') break;
            //if (dist[t.first][t.second + i] <= dist[t.first][t.second]) break;
            //dist[t.first][t.second + i] = dist[t.first][t.second] + 1;
            //if (dist[t.first][t.second + i] <= 2)
            //    q.push(mp(t.first, t.second + i));
            for (int j = 0; j < n; j++) {
                int x1 = t.first - j;
                int y1 = t.second + i;
                if (x1 < 0) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }

            for (int j = 0; j < n; j++) {
                int x1 = t.first + j;
                int y1 = t.second + i;
                if (x1 >= n) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }
        }

    for (int i = 1; i < n; i++)
        if (t.first - i >= 0) {
                if (a[t.first - i][t.second] != '.' && a[t.first - i][t.second] != 'S') break;
                //if (dist[t.first - i][t.second] <= dist[t.first][t.second]) break;
            //dist[t.first - i][t.second] = dist[t.first][t.second] + 1;
            //if (dist[t.first - i][t.second] <= 2)
             //   q.push(mp(t.first - i, t.second));
             for (int j = 0; j < m; j++) {
                int x1 = t.first - i;
                int y1 = t.second - j;
                if (y1 < 0) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }

            for (int j = 0; j < m; j++) {
                int x1 = t.first - i;
                int y1 = t.second + j;
                if (y1 >= m) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }
        }

    for (int i = 1; i < n; i++)
        if (t.first + i < n) {
                if (a[t.first + i][t.second] != '.' && a[t.first + i][t.second] != 'S') break;
                //if (dist[t.first + i][t.second] <= dist[t.first][t.second]) break;
            //dist[t.first + i][t.second] = dist[t.first][t.second] + 1;
            //if (dist[t.first + i][t.second] <= 2)
            //    q.push(mp(t.first + i, t.second));
            for (int j = 0; j < m; j++) {
                int x1 = t.first + i;
                int y1 = t.second - j;
                if (y1 < 0) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }

            for (int j = 0; j < m; j++) {
                int x1 = t.first + i;
                int y1 = t.second + j;
                if (y1 >= m) break;
                if (a[x1][y1] != '.' && a[x1][y1] != 'S') break;
                if (dist[x1][y1] < INF) {
                    cout << "YES";
                    return 0;
                }
            }
        }

    cout << "NO";



}