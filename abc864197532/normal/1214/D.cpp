#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,int>
#define X first
#define Y second
#define MAXN 100087
int n,m;
vector <vector <int>> vi;

bool dfs(int a, int b) {
    if (a == n - 1 and b == m - 1) return true;
    vi[a][b] = true;
    bool ans = false;
    if (a + 1 < n and !vi[a+1][b]) {
        ans |= dfs(a+1, b);
    }
    if (ans) return ans;
    if (b + 1 < m and !vi[a][b+1]) {
        ans |= dfs(a, b+1);
    }
    return ans;
}

int main () {
    cin >> n >> m;
    char c;
    vi.resize(n);
    fop (i,0,n) {
        vi[i].resize(m);
        fop (j,0,m) {
            cin >> c;
            if (c == '#') vi[i][j] = true;
            else vi[i][j] = false;
        }
    }
    vi[0][0] = true;
    int k = 0;
    if (n > 1 and !vi[1][0]) k += dfs(1, 0);
    if (m > 1 and !vi[0][1]) k += dfs(0, 1);
    cout << k << endl;
}