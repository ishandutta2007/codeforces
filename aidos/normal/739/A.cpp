#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)998244353;
const int inf = (1<<30) - 1;
int n, m;

void solve() {
    cin >> n >> m;
    int len = n;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        len = min(r-l+1,len);
    }
    cout << len << "\n";
    for(int i = 0; i < n; i++) cout << i % len << " ";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}