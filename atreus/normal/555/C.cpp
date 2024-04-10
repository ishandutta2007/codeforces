/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;

int x[maxn], y[maxn], ans[maxn];
char dir[maxn];
map<int, bool> mp;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<pair<int, int> > s;
	for (int i = 1; i <= m; i++){
		cin >> x[i] >> y[i] >> dir[i];
		if (mp.count(x[i])){
			cout << 0 << '\n';
			continue;
		}
		mp[x[i]] = 1;
		if (dir[i] == 'U'){
			auto it = s.lower_bound(make_pair(x[i], 0));
			if (it == s.end())
				ans[i] = y[i];
			else if (dir[(*it).second] == 'L')
				ans[i] = (*it).first - x[i];
			else
				ans[i] = ans[(*it).second] + (*it).first - x[i];
		}
		else{
			auto it = s.upper_bound(make_pair(x[i], 0));
			if (it == s.begin())
				ans[i] = x[i];
			else{
				it --;
				if (dir[(*it).second] == 'U')
					ans[i] = x[i] - (*it).first;
				else
					ans[i] = ans[(*it).second] + x[i] - (*it).first;
			}
		}
		cout << ans[i] << '\n';
		s.insert({x[i], i});
	}
}