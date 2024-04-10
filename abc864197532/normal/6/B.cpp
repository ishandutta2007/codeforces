#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    char c;
    cin >> n >> m >> c;
    string input[n];
    fop (i,0,n) cin >> input[i];
    set <char> ans;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    fop (i,0,n) {
        fop (j,0,m) {
            fop (k,0,4) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                if (input[nx][ny] == c) ans.insert(input[i][j]);
            }
        }
    }
    ans.erase(c);
    ans.erase('.');
    cout << ans.size() << '\n';
}