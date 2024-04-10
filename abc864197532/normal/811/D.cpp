#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 1000087, logN = 17, K = 333;

pii ask(char c) {
    cout << c << endl;
    int x, y;
    cin >> x >> y;
    return mp(x, y);
}

bool vis[102][102];
int pt[102][102], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <string> s(n + 2, string(m + 2, '#'));
    for (int i = 1; i <= n; ++i) cin >> s[i], s[i] = '#' + s[i] + '#';
    int fx, fy;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 'F') tie(fx, fy) = mp(i, j);
        }
    }
    queue <pii> q;
    q.emplace(fx, fy);
    vis[fx][fy] = true;
    while (q.size()) {
        int cx, cy;
        tie(cx, cy) = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (s[nx][ny] == '.' && !vis[nx][ny]) {
                pt[nx][ny] = k;
                vis[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
    int cx = 1, cy = 1, UD = -1, RL = -1;
    while (cx != fx || cy != fy) {
        if (pt[cx][cy] < 2) {
            if (RL == -1) {
                int nx, ny;
                tie(nx, ny) = ask('R');
                if (nx == cx && ny == cy) RL = 1;
                else RL = 0;
                cx = nx, cy = ny;
            } else {
                tie(cx, cy) = ask((pt[cx][cy] ^ RL) == 0 ? 'L' : 'R');
            }
        } else {
            if (UD == -1) {
                int nx, ny;
                tie(nx, ny) = ask('D');
                if (nx == cx && ny == cy) UD = 1;
                else UD = 0;
                cx = nx, cy = ny;
            } else {
                tie(cx, cy) = ask((pt[cx][cy] ^ UD) == 2 ? 'U' : 'D');
            }
        }
    }
}