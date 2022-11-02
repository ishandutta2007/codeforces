#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int cnt[maxn];
int x;
void solve() {
    cin >> n >> x;
    for(int i = 1; i < n; i++) {
        int y;
        cin >> y;
        cnt[y]++;
    }
    int pos = 1000;
    int ans = 0;
    while(true) {
        while(cnt[pos] == 0) pos--;
        if(pos < x) break;
        cnt[pos]--;
        cnt[pos-1]++;
        x++;
        ans++;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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