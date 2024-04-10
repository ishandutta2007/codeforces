#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXM = 2e5 + 10;
const int MAXQ = 2e5 + 10;
const int MAXN = 1000 + 5;

int n, last[MAXN];
bitset<MAXN> dp[MAXM];
vector<pair<int, int> > Q[MAXM];
string answer[MAXQ];
int s[MAXQ], t[MAXQ];
pair<int,int> e[MAXM];

void find(int L, int R){
	if (L + 1 == R){
		while (!Q[L].empty() and Q[L].back().first == L){
			int idx = Q[L].back().second;
			answer[idx] = "Yes";
			Q[L].pop_back();
		}
		return;
	}
	int mid = (L + R) >> 1;
	find(L, mid);
	find(mid, R);
	for (int i = mid; i < R; i++){
		int v = e[i].first, u = e[i].second;
		dp[i][v] = dp[i][u] = 1;
		if (last[v] != -1)
			dp[i] |= dp[last[v]];
		if (last[u] != -1)
			dp[i] |= dp[last[u]];
		last[v] = last[u] = i;
	}
	for (int i = mid; i < R; i++)
		last[e[i].first] = last[e[i].second] = -1;
	for (int i = mid - 1; i >= L; i--){
		int v = e[i].first, u = e[i].second;
		dp[i][v] = dp[i][u] = 1;
		if (last[v] != -1)
			dp[i] |= dp[last[v]];
		if (last[u] != -1)
			dp[i] |= dp[last[u]];
		last[v] = last[u] = i;
		while (!Q[i].empty() and Q[i].back().first < R){
			int idx = Q[i].back().second, k = Q[i].back().first;
			bitset<MAXN> now = dp[i] & dp[k];
			if (now.count() > 0)
				answer[idx] = "Yes";
			else
				answer[idx] = "No";
			Q[i].pop_back();
		}
	}
	for (int i = L; i < mid; i++)
		last[e[i].first] = last[e[i].second] = -1;
	for (int i = L; i < R; i++)
		dp[i].reset();
}


set<int> sidx[MAXN];

int main(){
	ios_base::sync_with_stdio (false);
	int m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++){
		cin >> e[i].first >> e[i].second;
		if (e[i].first > e[i].second)
			swap(e[i].first, e[i].second);
		sidx[e[i].first].insert(i);
		sidx[e[i].second].insert(i);
	}
	for (int i = 1; i <= q; i++){
		int l, r;
		cin >> l >> r >> s[i] >> t[i];
		auto it = sidx[s[i]].lower_bound(l);
		if (it == sidx[s[i]].end() or *it > r){
			answer[i] = "No";
			continue;
		}
		l = *it;
		it = sidx[t[i]].upper_bound(r);
		if (it == sidx[t[i]].begin()){
			answer[i] = "No";
			continue;
		}
		it --;
		if (*it < l){
			answer[i] = "No";
			continue;
		}
		r = *it;
		Q[l].push_back({r, i});
	}
	for (int i = 1; i <= m; i++)
		sort(Q[i].begin(), Q[i].end(), greater<pair<int, int> >());
	
	memset(last, -1, sizeof last);
	find(1, m + 1);
	for (int i = 1; i <= q; i++)
		cout << answer[i] << '\n';
}