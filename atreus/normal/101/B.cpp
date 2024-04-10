#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <set>

#define F first
#define S second

using namespace std;

const int mod = 1e9 + 7, maxn = 1e6 + 500;
map <int, int> dp, sum;
map <int, vector <int> > mp;
vector <int> v;
pair <int, int> p[maxn];

int main (){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> p[i].F >> p[i].S;
		v.push_back(p[i].S);
		mp[p[i].S].push_back(p[i].F);
	}
	if (v.empty())
		return cout << 0, 0;
	v.push_back(0);
	v.push_back(n);
	sort (v.begin(), v.end());
	vector<int>::iterator it = unique (v.begin(), v.end());
	v.resize(distance(v.begin(), it));
	dp[0] = 1;
	sum[0] = 1;
	for (int p = 1; p < v.size(); p++){
		int i = v[p];
		for (int j = 0; j < mp[i].size(); j++){
			int idx = lower_bound(v.begin(), v.end(), mp[i][j]) - v.begin();
			idx --;
			int k;
			if (idx == -1)
				k = 0;
			else
				k = v[idx];
//			cout << i << " - > " << v[p - 1] << " " << sum[v[p - 1]] << " - " << v[idx] << " " << sum[idx] << endl;
			dp[i] = (((dp[i] + sum[v[p - 1]] - sum[v[idx]]) % mod) + mod) % mod;
		}
		sum[i] = (sum[v[p - 1]] + dp[i]) % mod;
//		cout << i << " " << dp[i] << " " << sum[i] << endl;
	}
	cout << dp[n] << endl;
}