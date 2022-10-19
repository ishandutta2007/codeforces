#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 100015;
int t, n, a[N];
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		int cnt = 0;
		ll sum = 0;
		bool flag = 0;
		rep(i, 2, n - 1) {
			sum += a[i];
			if (a[i] & 1) cnt++;
			if (a[i] > 1) flag = 1;
		}
		if (cnt > 0 && (n == 3 || !flag)) {
			cout << "-1" << endl;
		} else {
			cout << (sum + cnt) / 2 << endl;
		}
	}
	return 0;
}