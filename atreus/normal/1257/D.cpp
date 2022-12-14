#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn], b[maxn], suf[maxn], dp[maxn];
pair<int, int> p[maxn];

int get(vector<int> &c, int x){
	int lo = -1, hi = c.size() - 1;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (c[mid] > x)
			lo = mid;
		else
			hi = mid;
	}
	return c[hi];
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		for (int i = 1; i <= n + 1; i++)
			b[i] = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> p[i].second >> p[i].first;
		sort(p, p + m);
		suf[m] = 0;
		for (int i = m - 1; i >= 0; i--){
			suf[i] = max(suf[i + 1], p[i].second);
			b[p[i].first] = suf[i];
		}
		for (int i = n; i >= 1; i--)
			b[i] = max(b[i], b[i + 1]);
		dp[n] = 0;
		vector<int> st;
		for (int i = n - 1; i >= 0; i--){
			while (!st.empty() and a[st.back()] <= a[i])
				st.pop_back();
			st.push_back(i);
			int lo = 0, hi = n - i + 1;
			while (hi - lo > 1){
				int mid = (lo + hi) >> 1;
				int fi = a[get(st, i + mid - 1)];
				int se = b[mid];
//				cout << "# " << i << " " << mid << " -> " << fi << " and " << se << endl;
				if (se >= fi)
					lo = mid;
				else
					hi = mid;
			}
//			cout << i << " -> " << lo << endl;
			if (lo == 0)
				dp[i] = - (n + 1);
			else
				dp[i] = dp[i + lo] + 1;
		}
		if (dp[0] < 0)
			dp[0] = -1;
		cout << dp[0] << '\n';
	}
}