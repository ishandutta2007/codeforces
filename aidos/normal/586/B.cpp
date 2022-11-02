#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
vector<int> pref;
int n;
int a[2][maxn];
int b[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j < n; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j-1];
        }
    }
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> d;
    for(int i = 0; i < n; i++) {
        d.emplace_back(a[0][i] + b[i] + a[1][n-1] - a[1][i]);
    }
    sort(d.begin(), d.end());
    cout << d[0] + d[1] << "\n";
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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