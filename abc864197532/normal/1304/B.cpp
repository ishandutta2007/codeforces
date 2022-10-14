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
#define X first
#define Y second
#define MAXN 200000

int main () {
    int n, m;
    cin >> n >> m;
    string s[n], rs[n];
    fop (i,0,n) {
        cin >> s[i];
        rs[i] = s[i];
        reverse(rs[i].begin(), rs[i].end());
    }
    vector <pii> nums;
    bool used[n];
    fop (i,0,n) used[i] = false;
    fop (i,0,n) {
        if (used[i]) continue;
        fop (j,i+1,n) {
            if (used[j]) continue;
            if (s[i] == rs[j]) {
                nums.pb({i, j});
                used[i] = used[j] = true;
                break;
            }
        }
    }
    int p = -1;
    fop (i,0,n) {
        if (!used[i] and s[i] == rs[i]) p = i;
    }
    vector <string> ans;
    for (auto i : nums) {
        ans.pb(s[i.X]);
    }
    if (p != -1) ans.pb(s[p]);
    reverse(nums.begin(), nums.end());
    for (auto i : nums) {
        ans.pb(s[i.Y]);
    }
    cout << ans.size() * m << endl;
    for (string s : ans) {
        cout << s;
    }
    cout << endl;
}