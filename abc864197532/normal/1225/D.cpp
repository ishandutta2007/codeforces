#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>

vector <int> lastPrime (int n) {
	vector <int> ans(n+1,0);
	for (int i = 2; i <= n; ++i) {
		if (ans[i] == 0) {
			for (int j = i; j <= n; j += i) {
				if (ans[j] == 0) ans[j] = i;
			}
		}
	}
	return ans;
}

int main () {
	int n,k,tmp;
	lli ans=0;
	cin >> n >> k;
	map <vector <pii>, int> ma;
	vector <int> LPrime = lastPrime(100000);
	fop (i,0,n) {
		cin >> tmp;
		vector <pii> aa;
		int b = 0;
		while (true) {
			if (tmp == 1 || b != LPrime[tmp]) {
				if (aa.size()) {
					if (aa[aa.size()-1].second % k == 0) aa.erase(aa.end()-1);
					else aa[aa.size()-1].second %= k;
				}
				if (tmp == 1) break;
				b = LPrime[tmp];
				aa.eb(b, 1);
			} else {
				aa[aa.size()-1].second++;
			}
			tmp /= LPrime[tmp];
		}
		ans += ma[aa];
		fop (i,0,aa.size()) {
			aa[i].second = k - aa[i].second;
		}
		if (ma.count(aa)) ma[aa]++;
		else ma[aa] = 1;
	}
	cout << ans << endl;
}