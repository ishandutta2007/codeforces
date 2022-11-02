#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e5 + 123;
const int mod = 1e9 + 9;
string s;
int n, m;
int a[maxn], b[maxn];
void solve() {
    cin >> n;
    int cur = -1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            if(cur != -1) {
                ans += i - cur - 1;
            }
            cur = i;
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}