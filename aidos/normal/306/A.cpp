#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x = n/(m-i);
        n -= x;
        cout << x << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
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