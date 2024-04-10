# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;
int T, n;
int c[MAXN];
ll f[100], s[100];
bool flg[100];
bool chk(int x, int ps, int typ = 0){
	while (x){
		int nw = upper_bound(f + 1, f + 44 + 1, x) - f - 1;
		if (nw > ps) return false;
		if (nw <= typ) return false;
		// cerr << "x " << x << ' ' << nw << ' ' << f[nw] << '\n';
		if (flg[nw]) return false;
		flg[nw] = true;
		x -= f[nw];
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	s[0] = 1;
	s[1] = 2;
	f[0] = f[1] = 1;
	for (int i = 2; i <= 44; i++){
		f[i] = f[i - 1] + f[i - 2];
		s[i] = s[i - 1] + f[i];
		// cerr << "f " << i << ' ' << f[i] << ' ' << s[i] << '\n';
	}
	cin >> T;
	while (T--){
		memset(flg, false, sizeof(flg));
		cin >> n;
		ll ns = 0;
		for (int i = 1; i <= n; i++){
			cin >> c[i];
			ns += c[i];
		}
		int ps = lower_bound(s, s + 44 + 1, ns) - s;
		if (s[ps] != ns){
			cout << "NO\n";
			continue;
		}
		bool suc = false;
		for (int j = 1; j <= n; j++){
			memset(flg, false, sizeof(flg));
			suc = true;
			for (int i = 1; i <= n; i++){
				int x = i == j ? c[i] - 1 : c[i];
				if (!chk(x, ps, i == j)){
					suc = false;
					break;
				}
			}
			if (suc) break;
		}
		if (suc) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}