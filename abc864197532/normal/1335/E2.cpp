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
const int mod = 998244353;

int main () {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> input(n), pos[201];
        fop (i,0,n) cin >> input[i], pos[input[i]].pb(i);
        int true_ans = 0;
        auto check = [&](int k) {
            //cout << k << endl;
            int l = 0, r = pos[k].size() - 1;
            vector <int> count(300, 0), num(n + 1, 0);
            int maxx = 0, c = 0, ans = 0;
            fop (i,0,n) count[input[i]]++;
            fop (i,0,300) {
            	num[count[i]]++;
            	maxx = max(maxx, count[i]);
			}
			true_ans = max(true_ans, maxx);
            if (l >= r) return 0;
			int ll = 0, rr = n - 1;
			while (l < r) {
				//cout << pos[k][l] << ' ' << pos[k][r] << endl;
				while (ll <= pos[k][l]) {
					num[count[input[ll]]]--;
					count[input[ll]]--;
					num[count[input[ll]]]++;
					ll++;
					if (num[maxx] == 0) maxx--;
				}
				while (rr >= pos[k][r]) {
					num[count[input[rr]]]--;
					count[input[rr]]--;
					num[count[input[rr]]]++;
					rr--;
					if (num[maxx] == 0) maxx--;
				}
				ans = max((l + 1) * 2 + maxx, ans);
				l++;
				r--;
			}
            return ans;
        };
        fop (i,1,201) true_ans = max(true_ans, check(i));
        
        cout << true_ans << '\n';
    }
}