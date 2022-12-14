/**
 *    author:  Atreus
 *    created: 22.01.2019
 **/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 100;
int a[maxn], b[maxn], c[maxn], d[maxn], k[maxn];
vector<pair<int, int> > note[maxn], actor[maxn];
stack<int> stck[maxn];
ll fen[maxn];
int ans[maxn];

void add(int idx, int x){
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] += x;
}

ll get(int idx){
	ll ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> cmp;
	for (int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		cmp.push_back(a[i]);
		cmp.push_back(b[i]);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> c[i] >> d[i] >> k[i];
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 0; i < n; i++){
		a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1;
		b[i] = lower_bound(cmp.begin(), cmp.end(), b[i]) - cmp.begin() + 1;
		note[a[i]].push_back({b[i], i});
	}
	for (int i = 0; i < m; i++){
		c[i] = lower_bound(cmp.begin(), cmp.end(), c[i]) - cmp.begin() + 1;
		d[i] = upper_bound(cmp.begin(), cmp.end(), d[i]) - cmp.begin();
		if (c[i] > d[i])
			continue;
		actor[c[i]].push_back({d[i], i});
	}
	int q = cmp.size();
	for (int l = 1; l <= q; l++){
		for (auto it : actor[l]){
			add(it.first, k[it.second]);
			stck[it.first].push(it.second);
		}
		for (auto it : note[l]){
			int r = it.first;
			int lo = r - 1, hi = q + 1;
			while (hi - lo > 1){
				int mid = (lo + hi) >> 1;
				if (get(mid) - get(r - 1) > 0)
					hi = mid;
				else
					lo = mid;
			}
			if (hi == q + 1)
				return cout << "NO" << endl, 0;
			ans[it.second] = stck[hi].top();
			k[stck[hi].top()] --;
			if (k[stck[hi].top()] == 0)
				stck[hi].pop();
			add(hi, -1);
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << ans[i] + 1 << " ";
	cout << endl;
}