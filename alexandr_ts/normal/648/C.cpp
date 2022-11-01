#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e2 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

char a[N][N];
bool used[N][N];
string ans;

int n,m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
string t = "LRUD";

void dfs(int x, int y) {
    //cout << x << " " << y << endl;
    used[x][y] = true;
    fr(i, 4) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == '*' && !used[x1][y1]) {
            ans += t[i];
            dfs(x1, y1);
            return;
        }

    }
    fr(i, 4) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == 'S') {
            ans += t[i];
            break;
        }
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int pi, pj;
    fr(i, n)
        fr(j, m) {
            cin >> a[i][j];
            if (a[i][j] == 'S')
                pi = i, pj = j;
        }
    dfs(pi, pj);
    cout << ans;


}