#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

vector<int> st[2*maxn];
int len[2*maxn];
int pd[259], dp[259];
pair<int,int> e[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> pnt;
	for (int i = 1; i <= n; i++){
		int l, r;
		cin >> l >> r;
		pnt.push_back(l);
		pnt.push_back(r+1);
		e[i] = {l,r+1};
	}
	sort(pnt.begin(), pnt.end());
	pnt.resize(unique(pnt.begin(), pnt.end()) - pnt.begin());
	for (int i = 1; i <= n; i++){
		int l = e[i].first, r = e[i].second;
		l = lower_bound(pnt.begin(), pnt.end(), l) - pnt.begin() + 1;
		r = lower_bound(pnt.begin(), pnt.end(), r) - pnt.begin() + 1;
		for (int j = l; j < r; j++)
			st[j].push_back(i);
		e[i] = {l,r};
	}
	for (int i = 1; i <= (int)pnt.size(); i++)
		sort(st[i].begin(), st[i].end());
	for (int i = 1; i <= (int)pnt.size() - 1; i++)
		len[i] = pnt[i] - pnt[i-1];
	
	for (int i = 1; i <= (int)pnt.size(); i++){
		int eq = 0, beq = 0;
		vector<int> A, B;
		for (int j = 0; j < (int)st[i].size(); j++){
			for (int k = 0; k < (int)st[i-1].size(); k++){
				if (st[i][j] == st[i-1][k]){
					eq |= (1 << j), beq |= (1 << k);
					A.push_back(j);
					B.push_back(k);
				}
			}
		}
		memset(pd, 0, sizeof pd);
		int sz = (int)st[i-1].size();
		for (int mask = 0; mask < (1 << sz); mask++){
			int sub = (mask & beq);
			int go = 0;
			for (int i = 0; i < sz; i++)
				if (sub & (1 << i))
					for (int j = 0; j < B.size(); j++)
						if (B[j] == i)
							go |= (1 << A[j]);
			pd[go] = max(pd[go], dp[mask]);
		}
		sz = (int)st[i].size();
		for (int mask = 0; mask < (1 << sz); mask++){
			int cnt = __builtin_popcount(mask);
			if (cnt & 1)
				dp[mask] = pd[(mask & eq)] + len[i];
			else
				dp[mask] = pd[(mask & eq)];
		}
	}
	cout << *max_element(dp, dp + 256) << '\n';
}