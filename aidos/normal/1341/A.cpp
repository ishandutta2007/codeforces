#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int x, n, m;
int a[maxn];
void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if(c+d >= n * (a-b) && (c-d) <= n * (a + b)) {
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}