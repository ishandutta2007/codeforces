#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli> 
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    lli all = 0;
    vector <int> input(m);
    fop (i,0,m) cin >> input[i], all += input[i];
    if (all < n) {
        cout << -1 << endl;
        return 0;
    }
    vector <int> ans(m);
    iota(ans.begin(), ans.end(), 0);
    int now = n;
    bool is = true;
    FOP (i,m,0) {
        if (ans[i] + input[i] >= now) break;
        ans[i] = now - input[i];
        now -= input[i];
    }
    fop (i,0,m) {
        if (i + input[i] > n) is = false;
    }
    if (!is) {
        cout << -1 << endl;
    } else {
        for (int i : ans) cout << i + 1 << ' ';
    }
}