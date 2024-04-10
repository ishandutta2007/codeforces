#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pr;

const int N = 2e3 + 1;
const ll INF = 2e9;
const ll MAX = 2e6 + 1;
const ll ALPH = 300;
const ld PI = acos(-1);
const int MOD = 1e9 + 7;

char a[N][N];
int dist[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct tmp {
    int x, y, dist;
} ar[N * N];

bool cmp(tmp a, tmp b) {
    return a.dist < b.dist;
}

int main() {
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, k;
    int px = -1, py = -1;
    cin >> n >> m >> k;
    fr(i, n)
        fr(j, m)
            dist[i][j] = INF;
    fr(i, n)
        fr(j, m) {
            cin >> a[i][j];
            if (a[i][j] == '.')
                px = i, py = j;
        }
    queue <pr> q;
    if (px != -1) {
        q.push(mp(px, py));
        dist[px][py] = 0;
    }
    while (q.size()) {
        pr v = q.front();
        q.pop();
        fr(i, 4) {
            int x = v.first + dx[i];
            int y = v.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && dist[x][y] == INF) {
                q.push(mp(x, y));
                dist[x][y] = dist[v.first][v.second] + 1;
            }
        }
    }

    fr(i, n)
        fr(j, m)
            ar[i * m + j] = {i, j, dist[i][j]};
    sort(ar, ar + n * m, cmp);
    reverse(ar, ar + n * m);
    fr(i, n * m)
        if (ar[i].dist != INF && k)
            a[ar[i].x][ar[i].y] = 'X', k--;
    fr(i, n){
        fr(j, m)
            cout << a[i][j];cout << endl;}


}