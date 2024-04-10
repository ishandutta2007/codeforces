#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int a[maxn];
int n;
pii b[maxn];
void solve() {
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        s.insert(i);
        b[i] = make_pair(a[i], i);
    }
    sort(b, b + n);
    ll ans = 0;
    for(int i = 0; i < n - 2; i++) {
        if(*s.begin() == b[i].second) {
            ans += b[i].first;
            s.erase(s.begin());
        } else if(*(--s.end()) == b[i].second) {
            ans += b[i].first;
            s.erase(--s.end());
        } else {
            s.erase(b[i].second);
            auto it = s.lower_bound(b[i].second);
            int x = a[*it];
            it--;
            x = min(x, a[*it]);
            ans += x;
        }
    }
    cout << ans << "\n";
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