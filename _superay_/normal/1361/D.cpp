#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, k;
map<pair<int, int>, vector<pair<int, int> > > mp;
inline double getdist(pair<int, int> p1, pair<int, int> p2) {
	return sqrt(1ll * (p1.first - p2.first) * (p1.first - p2.first)
		+ 1ll * (p1.second - p2.second) * (p1.second - p2.second));
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		pair<int, int> pr;
		scanf("%d%d", &pr.first, &pr.second);
		if (pr.first || pr.second) {
			int g = abs(__gcd(pr.first, pr.second));
			mp[make_pair(pr.first / g, pr.second / g)].push_back(pr);
		}
	}
	priority_queue<double> pq;
	for (auto &it : mp) {
		vector<pair<int, int> > &vec = it.second;
		vector<double> vd(vec.size());
		sort(vec.begin(), vec.end(), [](pair<int, int> p1, pair<int, int> p2) {
			return abs(p1.first) >= abs(p2.first) && abs(p1.second) >= abs(p2.second);
		});
		double su = 0;
		for (int i = 0; i < (int)vec.size(); i++) {
			vd[i] = (i < (int)vec.size() - 1 ? getdist(vec[i], vec[i + 1]) : getdist(vec[i], make_pair(0, 0)));
			su += vd[i];
		}
		int k1 = min((k + 1) >> 1, (int)vec.size());
		for (int i = 0; i < k1; i++) {
			pq.push(su * (k - (2 * i + 1)));
			su -= vd[i];
		}
		int k2 = min(k, (int)vec.size()) - k1;
		su = 0;
		double s2 = 0;
		for (int i = 0, j = (int)vec.size() - 1; i < k2; i++, j--) {
			s2 += vd[j] * (k - (2 * k1 + 1)) - 2 * su;
			pq.push(s2);
			su += vd[j];
		}
	}
	pq.push(0);
	int T = k;
	double ans = 0;
	while (T-- && !pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	printf("%.10lf\n", ans);
	return 0;
}