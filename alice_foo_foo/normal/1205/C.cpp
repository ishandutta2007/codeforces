#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 55;
const int dx[3] = {2, 1, 0};
const int dy[3] = {0, 1, 2};

struct ele {
    int x, y;
    ele (int a = 0, int b = 0) : x(a), y(b) {}
};

queue <ele> q;
int ans[N][N];
int n;

inline int query(int x, int y, int _x, int _y) {
    cout << "?" << " " << x << " " << y << " " << _x << " " << _y << endl;
    int ans; cin >> ans; return ans ^ 1;
}

void solve(int res) {
    cout << "!" << endl;
    if(res) {
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= n; j++) {
                if((i + j) & 1) ans[i][j] ^= 1;
            }
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    memset(ans, -1, sizeof(ans));
    cin >> n; ans[1][1] = 1; ans[n][n] = 0; q.push(ele(1, 1));
    while(!q.empty()) {
        ele u = q.front(); q.pop();
        for(register int i = 0; i <= 2; i++) {
            int x = u.x + dx[i], y = u.y + dy[i];
            if(x > n || y > n) continue;
            if(ans[x][y] == -1) {
                int res = query(u.x, u.y, x, y);
                ans[x][y] = ans[u.x][u.y] ^ res;
                q.push(ele(x, y));
            }
        }
    }
    ans[1][2] = 1; q.push(ele(1, 2));
    while(!q.empty()) {
        ele u = q.front(); q.pop();
        for(register int i = 0; i <= 2; i++) {
            int x = u.x + dx[i], y = u.y + dy[i];
            if(x > n || y > n) continue;
            if(ans[x][y] == -1) {
                int res = query(u.x, u.y, x, y);
                ans[x][y] = ans[u.x][u.y] ^ res;
                q.push(ele(x, y));
            }
        }
    }
    ans[2][1] = query(2, 1, 2, 3) ^ ans[2][3]; q.push(ele(2, 1));
    while(!q.empty()) {
        ele u = q.front(); q.pop();
        for(register int i = 0; i <= 2; i++) {
            int x = u.x + dx[i], y = u.y + dy[i];
            if(x > n || y > n) continue;
            if(ans[x][y] == -1) {
                int res = query(u.x, u.y, x, y);
                ans[x][y] = ans[u.x][u.y] ^ res;
                q.push(ele(x, y));
            }
        }
    }
    for(register int i = 1; i <= n - 2; i++) {
        for(register int j = 1; j <= n - 1; j++) {
            if((i + j) % 2 == 0) {
                if(ans[i + 1][j + 1] != ans[i + 2][j]) {
                    int res = query(i, j, i + 2, j + 1);
                    solve(ans[i][j] ^ ans[i + 2][j + 1] ^ res);
                }
            }
        }
    }
    for(register int i = 1; i <= n - 1; i++) {
        for(register int j = 1; j <= n - 2; j++) {
            if((i + j) % 2 == 0) {
                if(ans[i + 1][j + 1] != ans[i][j + 2]) {
                    int res = query(i, j, i + 1, j + 2);
                    solve(ans[i][j] ^ ans[i + 1][j + 2] ^ res);
                }
            }
        }
    }
    for(register int i = 1; i <= n - 2; i++) {
        for(register int j = 1; j <= n - 1; j++) {
            if((i + j) % 2 == 0) {
                if(ans[i][j + 1] == ans[i + 1][j] && ans[i + 1][j + 1] == ans[i + 2][j] && (ans[i][j] ^ ans[i + 1][j + 1] ^ ans[i + 1][j] ^ ans[i + 2][j + 1]) == 0) {
                    int res = query(i, j, i + 2, j + 1);
                    solve(ans[i][j] ^ ans[i + 2][j + 1] ^ res);
                }
            }
        }
    }
    for(register int i = 1; i <= n - 1; i++) {
        for(register int j = 1; j <= n - 2; j++) {
            if((i + j) % 2 == 0) {
                if(ans[i + 1][j] == ans[i][j + 1] && ans[i + 1][j + 1] == ans[i][j + 2] && (ans[i][j] ^ ans[i + 1][j + 1] ^ ans[i][j + 1] ^ ans[i + 1][j + 2]) == 0) {
                    int res = query(i, j, i + 1, j + 2);
                    solve(ans[i][j] ^ ans[i + 1][j + 2] ^ res);
                }
            }
        }
    }
    return 0;
}