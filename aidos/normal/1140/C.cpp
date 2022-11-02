#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
pii a[maxn];
int b[maxn];

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a + n);
    reverse(a, a + n);
    ll ans = 0;
    ll sum = 0;
    set<pii> S;
    for(int i = 0; i < n; i++) {
        sum += a[i].second;
        S.insert(make_pair(a[i].second, i));
        while(S.size() > k) {
            sum -= S.begin()->first;
            S.erase(S.begin());
        }
        ans = max(ans, sum * a[i].first);
    }
    cout << ans << "\n";

}


int main() {
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