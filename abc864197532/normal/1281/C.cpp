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
int MOD = 1e9+7;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int x;
		string s;
		cin >> x >> s;
		int a[1001000];
		fop (i,0,s.length()) {
			a[i] = s[i] - '0';
		}
		int now = 0;
		lli ans = s.length();
		bool is = true;
		while (now < x) {
			if (is) {
				int aa = ans;
				fop (i,1,a[now]) {
					fop (j,now+1, aa) {
						a[i*(aa-now-1)+j] = a[j];
						ans++;
						if (ans >= x) {
							is = false;
							ans = aa;
							break;
						}
					}
					if (!is) break;
				}
			}
			if (!is) {
				ans += (1ll * (a[now]-1) * (ans-now-1));
				ans %= MOD;
			}
			now++;
		}
		if (ans < 0) ans += MOD;
		cout << ans << endl;
	}
}