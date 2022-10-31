#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<pair<int, int> > A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
		A[i].first = -A[i].first;
	}
	sort(A.begin(), A.end());
	set<int> st;
	st.insert(-1);
	st.insert(N);
	int t;
	for (int i = 0; i < N; i++) {
		st.insert(A[i].second);
		auto x = st.find(A[i].second);
		x--;
		int l = (*x);
		x++; x++;
		int r = (*x);
		int m = A[i].second;
		//cerr << l << " " << m << " " << r << endl;
		int cnt = 0;
		int mxn = (r - l - 1) / (K - 1);
	
		mxn -= 2;
		while (mxn*(K - 1) + 1 < r - l)mxn++;
		mxn--;
		//cerr << "mxn=" << mxn << endl;

		int mx = (r - m - 1) / (K - 1);
		mx -= 2;
		while (r - (mx*(K - 1) + 1) >= m)mx++;
		mx--;
		//cerr << "mx=" << mx << endl;
		cnt = (((cnt + mx * m) % MOD)) % MOD;
		t = (r - 1)*mxn % MOD;
		t -= (((mxn*(mxn + 1) / 2) % MOD) * (K - 1)) % MOD;

		t -= (r - 1)*mx % MOD;
		t += (((mx*(mx + 1) / 2) % MOD) * (K - 1)) % MOD;
		t %= MOD;
		cnt += t;
		cnt %= MOD;
		if (cnt < 0)cnt += MOD;

		mx = (m - l - 1) / (K - 1);
		mx -= 2;
		while (m - (mx*(K - 1) + 1) >= l)mx++;
		mx--;
		//cerr << "mx=" << mx << endl;
		cnt = (cnt - (((mxn - mx)*l) % MOD)) % MOD;
		t = (-(m - 1) * mx) % MOD;
		t += (((mx*(mx + 1) / 2) % MOD) * (K - 1)) % MOD;
		t %= MOD;
		cnt += t;
		cnt %= MOD;
		if (cnt < 0)cnt += MOD;

		//cnt += min(r - len, m) - max(l, m - len);



		//cerr << -A[i].first << " " << cnt << endl;
		res = (res + ((-A[i].first * (cnt)) % MOD)) % MOD;
	}
	cout << res << endl;
}