#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e2 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, m;
char c[111][111];
string a[111];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    for(int j = 0; j < m; j++) {
        int was = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] + c[i][j] < a[i-1] + c[i-1][j]) was = 0;
        }
        if(was == 0) continue;
        for(int i = 0; i < n; i++) a[i] += c[i][j];
    }
    cout << m - a[0].size() << "\n";
}

int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}