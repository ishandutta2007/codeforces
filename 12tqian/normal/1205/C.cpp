#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

template <class T> bool ckmin(T& a, T b) { return a > b ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, T b) { return a < b ? a = b, 1 : 0; }

int n;

bool ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << endl;
    int x; cin >> x;
    return x;
}

void finish(vector<vi> v) {
    cout << "!" << endl;
    f0r(i, n) {
        f0r(j, n) cout << v[i][j];
        cout << endl;
    }
    exit(0);
}

bool valid(int i, int j) {
    return i>=0&&j>=0&&i<n&&j<n;
}

void flip(vector<vi>& g) {
    f0r(i, n) {
        f0r(j, n) {
            if ((i+j)%2) {
                g[i][j] ^= 1;
            }
        }
    }
}

int ux[3] = {-2, 0, -1};
int uy[3] = {0, -2, -1};
int dx[3] = {2, 0, 1};
int dy[3] = {0, 2, 1};

void test(vector<vi>& g, int a, int b, int c, int d) {
    if (ask(a, b, c, d)) {
        if (g[a][b] != g[c][d]) {
            flip(g);
        } 
    } else {
        if (g[a][b] == g[c][d]) {
            flip(g);
        }
    }
}

int main() {
    cin >> n;
    vector<vi> g(n, vi(n, -1));

    g[0][0] = 1;
    g[0][1] = 0;

    function<void(int, int)> dfs = [&](int i, int j) {
        f0r(d, 3) {
            int ni = i + ux[d];
            int nj = j + uy[d];
            if (!valid(ni, nj)) continue;
            if (g[ni][nj] != -1) continue;
            if (ask(ni, nj, i, j)) {
                g[ni][nj] = g[i][j];
            } else {
                g[ni][nj] = g[i][j] ^ 1;
            }
            dfs(ni, nj);
        }
        f0r(d, 3) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (!valid(ni, nj)) continue;
            if (g[ni][nj] != -1) continue;
            if (ask(i, j, ni, nj)) {
                g[ni][nj] = g[i][j];
            } else {
                g[ni][nj] = g[i][j] ^ 1;
            }
            dfs(ni, nj);
        }
    };

    dfs(0, 0);
    dfs(0, 1);

    f0r(i, n) {
        f0r(j, n) {
            if (i && j < n-1) { // UR
                if (g[i][j] != g[i-1][j+1]) {
                    if (j) {
                        test(g, i-1, j-1, i, j+1);
                    } else {
                        test(g, i-1, j, i, j+2);
                    }
                    finish(g);
                }
            }
        }
    }
    f0r(i, n-1) {
        f0r(j, n-2) {
            if (g[i][j] == g[i+1][j+1] && g[i][j+1] == g[i+1][j+2]) {
                test(g, i, j, i+1, j+2);
                finish(g);
            }
            if (g[i][j] != g[i+1][j+1] && g[i][j+1] != g[i+1][j+2]) { 
                test(g, i, j, i+1, j+2);
                finish(g);
            }
        }
    }

    assert(false);

    return 0;
}