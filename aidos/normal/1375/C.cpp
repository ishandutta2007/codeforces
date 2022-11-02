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
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[0] < a[n-1]) {
        cout <<"YES\n";
    }else {
        cout <<"NO\n";
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