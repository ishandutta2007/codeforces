#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, x;
int a[maxn];
void solve() {
    cin >> n >> x;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i] % 2;
    }
    if(cnt == 0 || (x == n && cnt % 2 == 0)) {
        cout << "No\n";
        return;
    }
    if(cnt < n) {
        cout << "Yes\n";
        return;
    }
    if(x % 2 == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}