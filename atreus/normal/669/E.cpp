#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

pair<int,pair<int, int> > q[maxn];
vector<int> v[maxn];
int ans[maxn], fen[maxn];

int get(int idx){
	idx ++;
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

void add(int idx, int x){
	idx ++;
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += x;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> cmp;
	for (int i = 0; i < n; i++){
		int a, t, x;
		cin >> a >> t >> x;
		q[i] = {a, {t, x}};
		cmp.push_back(x);
		cmp.push_back(t);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 0; i < n; i++){
		q[i].second.first = lower_bound(cmp.begin(), cmp.end(), q[i].second.first) - cmp.begin();
		q[i].second.second = lower_bound(cmp.begin(), cmp.end(), q[i].second.second) - cmp.begin();
		v[q[i].second.second].push_back(i);
	}
	int m = cmp.size();
	for (int i = 0; i < m; i++){
		for (auto idx : v[i]){
			if (q[idx].first == 1)
				add(q[idx].second.first, +1);
			else if (q[idx].first == 2)
				add(q[idx].second.first, -1);
			else
				ans[idx] = get(q[idx].second.first);
		}	
		for (auto idx : v[i]){
			if (q[idx].first == 1)
				add(q[idx].second.first, -1);
			else if (q[idx].first == 2)
				add(q[idx].second.first, +1);
		}	
	}
	for (int i = 0; i < n; i++)
		if (q[i].first == 3)
			cout << ans[i] << '\n';
}