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
set<int> s[2];
int get(int id) {
    int x = *s[id].begin();
    s[id].erase(s[id].begin());
    int y = *s[id].begin();
    return y - x;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s[0].insert(x);
        s[1].insert(y);
    }
    if(s[0].size() != 2 || s[1].size() != 2) {
        cout << -1 << "\n";
        return;
    }
    cout << get(0) * get(1) << "\n";
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