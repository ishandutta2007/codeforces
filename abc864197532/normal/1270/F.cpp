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
    string s;
	cin >> s;
    int n = s.length(), k = 450;
    int pre[n+1];
	lli ans = 0;
    pre[0] = 0;
    vector <int> pos, id(n, -1);
    fop (i,0,n) {
        pre[i+1] = pre[i] + s[i] - '0';
        id[i] = pos.size();
        if (s[i] == '1') pos.pb(i);
    }
    pos.pb(n);
    fop (i,0,n) {
        fop (j,1, n / k + 1) {
            if (id[i] + j >= pos.size()) break;
            lli l = pos[id[i] + j - 1] - i + 1;
            lli r = pos[id[i] + j] - i;
            l = max(l, 1ll * j * (k + 1));
            if (r >= l) ans += (r / j - (l - 1) / j);
    	}
    }
    fop (i,1,k+1) {
        vector <lli> nums;
        fop (j,0,n+1) {
            nums.pb(1ll * i * pre[j] - j);
        }
        sort(nums.begin(), nums.end());
        for (int i = 1, before = 0; i < n + 1; ++i) {
            if (nums[i] != nums[before]) {
                ans += (1ll * (i - before) * (i - before - 1) / 2);
                before = i;
            }
            if (i == n) {
                ans += (1ll * (n + 1 - before) * (n + 1 - before - 1) / 2);
            }
        }
    }
	cout << ans << '\n';
}