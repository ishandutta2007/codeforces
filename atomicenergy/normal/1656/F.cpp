#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<long long > > g;
vector<bool> as;
void dfs(long long v, long long p, bool b) {
	as[v] = b;
	for (auto u : g[v]) {
		if (u == p) continue;
		dfs(u, v, !b);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t;
	cin >> t;
	while (t-- > 0) {
		long long n;
		cin >> n;
		
		vector<long long> v(n);
		set<pair<long long, long long> > s;
		long long sumneg = 0;
		long long highneg = -1000000;
		long long lowneg = 0;

		long long numzero = 0;
		long long sumpos = 0;
		long long highpos = 0;
		long long lowpos = 10000000;
		for (long long i = 0; i < n; i++) {

			
			cin >> v[i];
			s.insert({ i, v[i] });
			if (v[i] == 0) numzero++;
			if (v[i] > 0) {
				sumpos += v[i];
				if (v[i] > highpos) highpos = v[i];
				if (v[i] < lowpos) lowpos = v[i];
			}
			if (v[i] < 0) {
				sumneg += v[i];
				if (v[i] > highneg) highneg = v[i];
				if (v[i] < lowneg) lowneg = v[i];
			}
		}
		long long ans = 0;
		sort(v.begin(), v.end());
		if (sumpos != 0 && sumneg != 0) {
			bool ok = true;
			long long mx = -1000000000000000000;
			long long prod = lowneg * (sumneg + sumpos) - lowneg * lowneg;

			long long ts = sumneg + sumpos - lowneg + (lowneg) * (n - 1);
			if (ts > 0) ok = false;
			mx = max(mx, prod + (-v[0]) * ts);
			for (long long i = 1; i < n-1; i++) {
				mx = max(mx, prod + (-v[i]) * ts);

				prod -= lowneg * v[i];
				prod += highpos * v[i];

				ts -= lowneg;
				ts += highpos;
				mx = max(mx, prod + (-v[i]) * ts);

			}
			if (ts < 0) ok = false;
			mx = max(mx, prod + (-v[n-1]) * ts);
			if(!ok)cout << "INF" << endl;
			else cout << mx << endl;

		}
		else if (sumpos == 0 && sumneg != 0) {
			cout << "INF" << endl;
		}
		else if (sumneg == 0 && sumpos != 0) {
			cout << "INF" << endl;
		}
		else {
			cout << 0 << endl;
		}

		

		
	}
}