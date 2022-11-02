#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = 998244353;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int a[maxn];
vector<pii> ans;
void rec(int l, int r, int op) {
    while(l <= r && a[r] == r) {r--;}
    while(l <= r && a[l] == l) {l++;}
    if(l > r) {
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[ans.size()-i-1].first << " " << ans[ans.size()-i-1].second << "\n";
        exit(0);
    }
    if(op == 0) return;
    ans.emplace_back(make_pair(l, r));
    reverse(a + l, a + r + 1);
    rec(l, r, op-1);
    reverse(a + l, a + r + 1);
    ans.pop_back();
    if(op==1) return;
    vector<int> pos;
    pos.push_back(l);
    for(int i=l+1; i < r; i++) {
        if(abs(a[i] - a[i-1]) != 1 || abs(a[i] - a[i+1]) != 1) {
            pos.push_back(i);
        }
    }
    pos.push_back(r);
    for(int i = 0; i < pos.size(); i++) {
        for(int j = i + 1; j < pos.size(); j++) {
            reverse(a + pos[i], a + pos[j] + 1);
            ans.push_back(make_pair(pos[i], pos[j]));
            rec(l, r, op-1);
            reverse(a + pos[i], a + pos[j] + 1);
            ans.pop_back();
        }
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    rec(1, n, 3);
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