#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int occur[maxn];
ll answer[maxn];
int mp[maxn * 300];
int x[maxn], y[maxn];
int nex[maxn], pre[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n, k;
	cin >> n >> k;
	vector<pair<int, pair<int, int> > > events;
	vector<pair<int, int> > cmp;
	int mnm = 1000000000;
	for (int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		mnm = min(mnm, y[i]);
	}
	for (int i = 1; i <= n; i++){
		y[i] -= mnm;
		y[i] += k;
		cmp.push_back({y[i], i});
	}
	sort(cmp.begin(), cmp.end());
	for (int i = 0; i < cmp.size() - 1; i++){
		int idx = cmp[i].second;
		y[cmp[i + 1].second] = y[idx] + cmp[i + 1].first - cmp[i].first;
		if (cmp[i + 1].first - cmp[i].first > k)
			y[cmp[i + 1].second] = y[idx] + k;
	}
	for (int i = 1; i <= n; i++){
		events.push_back({x[i] - k + 1, {y[i] - k + 1, +1}});
		events.push_back({x[i] + 1, {y[i] - k + 1, -1}});
	}
	sort(events.begin(), events.end());
	int fi = 0;
	for (int i = 0; i < events.size() - 1; i++){
		int x = events[i].second.first;
		for (int j = x; j <= x + k - 1; j++){
			if (mp[j] != 0)
				occur[mp[j]] --;
			if (mp[j] != 0 and occur[mp[j]] == 0){
				nex[pre[mp[j]]] = nex[mp[j]];
				pre[nex[mp[j]]] = pre[mp[j]];
				if (fi == mp[j])
					fi = nex[fi];
				nex[mp[j]] = pre[mp[j]] = 0;
			}
			mp[j] += events[i].second.second;
			if (mp[j] != 0 and occur[mp[j]] == 0){
				pre[fi] = mp[j];
				nex[mp[j]] = fi;
				fi = mp[j];
			}
			if (mp[j] != 0)
				occur[mp[j]] ++;
		}
		if (events[i].first != events[i + 1].first){
			int diff = events[i + 1].first - events[i].first;
			if (diff > k)
				continue;
			for (int me = fi; me; me = nex[me])
				answer[me] += 1ll * diff * occur[me];
		}
	}
	for (int i = 1; i <= n; i++)
		cout << answer[i] << " \n"[i == n];
}