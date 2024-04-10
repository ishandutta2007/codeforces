#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;

int x[maxn], y[maxn], k[maxn];

ld dis(int i, int j){
	ld X = x[i] - x[j], Y = y[i] - y[j];
	return sqrt(X*X + Y*Y);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> k[0];
	x[0] = y[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i] >> k[i];
	n ++;
	vector<pair<ld, int>> v;
	for (int i = 1; i < n; i++)
		v.push_back({dis(0,i), k[i]});
	sort(v.begin(), v.end());
	int sum = k[0];
	for (auto it : v){
		sum += it.second;
		if (sum >= 1000*1000)
			return cout << fixed << setprecision(6) << it.first << endl, 0;
	}
	cout << -1 << endl, 0;
}