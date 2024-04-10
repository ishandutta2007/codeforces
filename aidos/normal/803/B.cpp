#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
int ans[maxn];
void solve() {
    cin >> n;
    int pos = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) pos = i;
        if(pos == -1) {
            ans[i] = inf;
        } else {
            ans[i] = i - pos;
        }
    }
    pos = -1;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == 0) pos = i;
        if(pos != -1) {
            ans[i] = min(ans[i], pos - i);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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