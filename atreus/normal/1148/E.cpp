#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 10;

int init[maxn], pos[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int> > a, b;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		init[i] = x;
		a.push_back({x, i});
	}
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		b.push_back({x, i});
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++)
		pos[i] = a[i].first - b[i].first;
	ll now = 0;
	for (int i = 0; i < n; i++){
		now += pos[i];
		if (now > 0)
			return cout << "NO\n", 0;
	}
	if (now != 0)
		return cout << "NO\n", 0;
	cout << "YES\n";
	vector<pair<pair<int, int>, int> > opes;
	stack<int> rem;
	for (int i = 0; i < n; i++){
		if (pos[i] < 0){
			rem.push(i);
			continue;
		}
		while (pos[i] > 0){
			int idx = rem.top();
			rem.pop();
			int d = min(pos[i], -pos[idx]);
			pos[i] -= d, pos[idx] += d;
			opes.push_back({{a[i].second, a[idx].second}, d});
			if (pos[idx] < 0)
				rem.push(idx);
		}
	}
	cout << opes.size() << '\n';
	for (auto it : opes){
		if (init[it.first.first] > init[it.first.second])
			swap(it.first.first, it.first.second);
		cout << it.first.first << " " << it.first.second << " " << it.second << '\n';
	}
}