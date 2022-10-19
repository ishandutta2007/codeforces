#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;

int T;
int n, m;
ll a[200200];
vector<int> to[200200];
ll sum[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, n)
			cin >> a[i];
		rep(i, n)
			cin >> sum[i];
		rep(i, n + 1)
			to[i].clear();
		rep(i, m){
			int x, y;
			cin >> x >> y;
			x--;
			to[x].push_back(y);
			to[y].push_back(x);
		}
		rep(i, n)
			a[i] = sum[i] - a[i];
		sum[0] = 0;
		rep(i, n)
			sum[i + 1] = sum[i] + a[i];
		set<int> st;
		queue< pair<int, int> > q;
		rep(i, n + 1){
			if(sum[i] != 0)
				st.insert(i);
			else {
				rep(j, (int)to[i].size()){
					if(sum[to[i][j]] == 0){
						q.push(make_pair(i, to[i][j]));
					}
				}
			}
		}
		while(!q.empty()){
			pair<int, int> p = q.front(); q.pop();
			int l = min(p.first, p.second), r = max(p.first, p.second);
//			cout << l << " " << r << endl;
			for(set<int>::iterator it = st.lower_bound(l); it != st.end() && *it < r; ){
				int i = *it;
//				cout << "del " << i << endl;
				sum[i] = 0;
				rep(j, (int)to[i].size()){
					if(sum[to[i][j]] == 0){
						q.push(make_pair(i, to[i][j]));
					}
				}
				set<int>::iterator nxt = it;
				nxt++;
				st.erase(it);
				it = nxt;
			}
		}
		bool ok = 1;
		rep(i, n + 1)
			if(sum[i] != 0)
				ok = 0;
		cout << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}