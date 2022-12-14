#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn], fen[maxn], ans[maxn];
vector<pair<int, int> > v[maxn];

void add(int idx){
	for (; idx < maxn; idx += idx & -idx)
		fen[idx] ++;
}

bool cmp(pair<int, int> fi, pair<int, int> se){
	if (fi.first != se.first)
		return fi > se;
	return fi < se;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int> > b;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b.push_back({a[i], i});
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int k, pos;
		cin >> k >> pos;
		v[k].push_back({pos, i});
	}
	sort(b.begin(), b.end(), cmp);
	int num = 0;
	for (auto it : b){
		int idx = it.second;
		add(idx);
		num ++;
		for (auto Query : v[num]){
			int now = 0;
			int pos = Query.first, idx = Query.second;
			for (int i = 18; i >= 0; i--){
				if (now + (1 << i) >= maxn)
					continue;
				if (fen[now + (1 << i)] < pos){
					pos -= fen[now + (1 << i)];
					now += (1 << i);
				}
			}
			ans[idx] = a[++ now];
		}
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << '\n';
}