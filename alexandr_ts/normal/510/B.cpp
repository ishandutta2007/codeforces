#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e3 + 1;
const ld EPS = 1e-8;
int n, m;
char a[N][N];
bool used[N][N];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool norm(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    fr(i, n)
        fr(j, m)
            cin >> a[i][j];
    fr(i1, n * m)
        fr(i, n)
            fr(j, m) {
                int cnt = 0;
                fr(k, 4) {
                    int x = i + dx[k], y = j + dy[k];
                    if (norm(x, y) && a[i][j] == a[x][y]) cnt++;
                }
                if (cnt <= 1)
                    a[i][j] = '.';
            }
    fr(i, n)
        fr(j,m)
            if (a[i][j] != '.')
            {
                cout << "Yes";
                return 0;
            }
    cout << "No";

}