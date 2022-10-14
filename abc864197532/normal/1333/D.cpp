#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector <vector <int>> ans;
    int all = 0;
    while (true) {
        ans.pb({});
        fop (i,1,n) {
            if (s[i - 1] == 'R' and s[i] == 'L') ans.back().pb(i), all++, swap(s[i - 1], s[i]), i++;
        }
        if (ans.back().empty()) {
            ans.pop_back();
            break;
        }
    }
    if (k < ans.size() or k > all) {
        cout << -1 << '\n';
        return 0;
    }
    int now = 0;
    while (k > ans.size() - now) {
        if (now == ans.size()) break; 
        k--;
        cout << 1 << ' ' << ans[now].back() << '\n';
        ans[now].pop_back();
        if (ans[now].empty()) now++;
    }
    fop (i,now,ans.size()) {
        cout << ans[i].size() << ' ';
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}