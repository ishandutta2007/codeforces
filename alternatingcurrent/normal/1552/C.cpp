#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, k;
vector< pair<int, int> > v;
bool used[222];
vector<int> rem;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		v.clear();
		rem.clear();
		memset(used, 0, sizeof(used));
		cin >> n >> k;
		rep(i, k){
			int a, b;
			cin >> a >> b;
			a--, b--;
			if(a > b)
				swap(a, b);
			v.push_back(make_pair(a, b));
			used[a] = used[b] = 1;
		}
		rep(i, n + n)
			if(!used[i])
				rem.push_back(i);
		int all = (int)rem.size() / 2;
		rep(i, all){
			v.push_back(make_pair(rem[i], rem[i + all]));
		}
		int ans = 0;
		rep(i, (int)v.size()){
			rep(j, i){
				if((v[i].first > v[j].first && v[i].first < v[j].second && v[j].second > v[i].first && v[j].second < v[i].second) || 
				   (v[j].first > v[i].first && v[j].first < v[i].second && v[i].second > v[j].first && v[i].second < v[j].second))
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}