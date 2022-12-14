#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 10;
const ll mod = 998244353;

int a[maxn];
map<int,int> cnt, ptr, deg;
map<pair<int,int>, int> mp;
map<int,int> last;
vector<int> occ[maxn];

ll cost(int x, int y) {
	return 1LL * (x + y) * (cnt[x] + cnt[y]);
}

void solve() {
	int n, m;
	cin >> n >> m;
	cnt.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	deg.clear();
	mp.clear();
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
		mp[{x,y}] = mp[{y,x}] = 1;
	}
	
	last.clear();
	vector<int> difCnt;
	for (int i = 1; i <= n; i++) {
		if (last[a[i]] != 0)
			continue;
		occ[cnt[a[i]]].push_back(a[i]);
		difCnt.push_back(cnt[a[i]]);
		last[a[i]] = i;
	}
	sort(difCnt.begin(), difCnt.end());
	difCnt.resize(unique(difCnt.begin(), difCnt.end()) - difCnt.begin());
	reverse(difCnt.begin(), difCnt.end());
	for (auto it : difCnt) {
		sort(occ[it].begin(), occ[it].end());
		reverse(occ[it].begin(), occ[it].end());
	}
	ll answer = 0;
	for (auto cntx : difCnt) {
		for (auto cnty : difCnt) {
			if (cnty < cntx)
				continue;
			int px = 0;
			int py = min(m + 1, (int)occ[cnty].size());
			for (auto x : occ[cntx]) {
				for (int i = 0; i < py; i++) {
					int y = occ[cnty][i];
					if (x != y and !mp[{x,y}]) {
						answer = max(answer, cost(x, y));
						py = i + 1;
						break;
					}
				}
			}
		}
	}
	cout << answer << '\n';
	for (int i = 1; i <= n; i++)
		occ[i].clear();
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}