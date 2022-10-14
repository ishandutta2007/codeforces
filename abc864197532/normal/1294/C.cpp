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
const int k = 32000;
 
 
int solve () {
    int n, now = 2, nowp = 1, tmp;
    cin >> n;
    tmp = n;
    set <int> ans;
    while (n > 1) {
        if (n % now == 0) {
            n /= now;
            nowp *= now;
            if (!ans.count(nowp)) {
                ans.insert(nowp);
                nowp = 1;
            }
        } else {
            now++;
        }
        if (ans.size() == 2 or now >= k) break;
    }
    for (int i : ans) tmp /= i;
    ans.insert(tmp);
    if (ans.size() == 3 and tmp != 1) {
        cout << "YES" << endl;
        for (int i : ans) cout << i << ' ';
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}