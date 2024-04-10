#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 100087

int main () {
	int n;
	cin >> n;
	lli a[n], count = 0, k = -1;
	fop (i,0,n) cin >> a[i], count += a[i];
	if (count == 1) {
		cout << -1 << endl;
		return 0;
	}
	set <int> f;
	for (int i = 1; i * i <= count; ++i) {
		if (count % i == 0) {
			f.insert(i);
			f.insert(count / i);
		}
	}
	lli ans = LLONG_MAX;
	for (int k : f) {
		if (k == 1) continue;
		lli aa = 0, now = 0;
		fop (i,0,n) {
			if (a[i] == 1) {
				now++;
				if (now == (k + 1) / 2) {
					if (!(k & 1)) aa -= i;
				} else if (now > (k + 1) / 2) {
					aa += i;
				} else {
					aa -= i;
				}
				if (now == k) now = 0;
			}
		}
		ans = min(ans, aa);
	}
	cout << ans << endl;
}