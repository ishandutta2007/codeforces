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

bool is_p (vector <int> a, int l, int r) {
    set <int> ss;
    fop (i,l,r) {
        ss.insert(a[i]);
    }
    fop (i,1,r-l+1) {
        if (!ss.count(i)) return false;
    }
    return true;
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> input(n);
        int s = 0;
        fop (i,0,n) cin >> input[i], s = max(input[i], s);
        set <int> ans;
        if (is_p(input, 0, s) and is_p(input, s, n)) ans.insert(s);
        if (is_p(input, 0, n - s) and is_p(input, n - s, n)) ans.insert(n - s);
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << ' ' << n - i << '\n';
    }
}