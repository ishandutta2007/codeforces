#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int a[maxn];
int n;
int cnt[22];
void solve() {
    cin >> n;
    vector< pair<int, int> > ans;
    int x = 0, y = 0;
    ans.emplace_back(make_pair(x, y));
    for(int i = 0; i < n + 1; i++) {
        ans.emplace_back(make_pair(x + 1, y));
        ans.emplace_back(make_pair(x, y + 1));
        ans.emplace_back(make_pair(x+1, y + 1));
        x++;
        y++;
    }
    cout << ans.size() << "\n";
    for(pair<int, int> x: ans) {
        cout << x.first << " "<< x.second << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
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