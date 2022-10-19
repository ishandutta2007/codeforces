#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, k;
int x[200200], y[200200], t[200200];
int par[200200], mnt[200200];
int getpar(int now){
	return par[now] = (par[now] == now) ? now : getpar(par[now]);
}
map< int, vector< pair<int, int> > > mp[2];

bool check(int mid){
	int cnt = 0;
	rep(i, n)
		if(par[i] == i && mnt[i] > mid)
			cnt++;
	return (cnt <= mid + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> k;
		mp[0].clear(), mp[1].clear();
		rep(i, n){
			cin >> x[i] >> y[i] >> t[i];
			mp[0][x[i]].push_back(make_pair(y[i], i));
			mp[1][y[i]].push_back(make_pair(x[i], i));
		}
		rep(i, n)
			par[i] = i, mnt[i] = t[i];
		rep(tp, 2) for(map< int, vector< pair<int, int> > >::iterator it = mp[tp].begin(); it != mp[tp].end(); it++){
			vector< pair<int, int> > v = it->second;
			sort(v.begin(), v.end());
			for(int i = 0; i < (int)v.size() - 1; i++){
				if(v[i + 1].first - v[i].first <= k){
					int p1 = getpar(v[i].second), p2 = getpar(v[i + 1].second);
					mnt[p1] = min(mnt[p1], mnt[p2]);
					par[p2] = p1;
				}
			}
		}
		int lb = 0, ub = 1e9; 
		while(lb <= ub){
			int mid = (lb + ub) >> 1;
			if(check(mid))
				ub = mid - 1;
			else
				lb = mid + 1;
		}
		cout << lb << endl;
	}
	return 0;
}