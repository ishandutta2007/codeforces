#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int cnt[maxn];
int a[maxn];
void solve() {
    cin >> n >> m;
    for(int i=0; i < n; i++) {
        cin >> a[i];
        int x = a[i] - i * m;
        if(x > 0) cnt[x]++;
    }
    int val = max_element(cnt, cnt + maxn) - cnt;
    cout << n - cnt[val] << "\n";
    for(int i = 0; i < n; i++) {
        if(a[i] > val + i * m) {
            cout << "- " << i + 1 <<" " << a[i] - (val + i * m) << "\n";
        } else if(a[i] < val + i * m) {
            cout << "+ " << i + 1 <<" " << -a[i] + (val + i * m) << "\n";
        }
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