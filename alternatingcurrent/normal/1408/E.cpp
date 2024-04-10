#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m;
int a[100100], b[100100];
//vector<int> v[200200];
vector< pair< int, pair<int, int> > > edge;
int par[200200];
int get_par(int now){
	return par[now] = (par[now] == now) ? now : get_par(par[now]); 
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	rep(i, n){
		int s;
		cin >> s;
		rep(j, s){
			int y;
			cin >> y;
			y--;
			edge.push_back(make_pair(a[i] + b[y], make_pair(i, y + n)));
		}
	}
	sort(edge.begin(), edge.end());
	reverse(edge.begin(), edge.end());
	long long ans = 0;
	rep(i, n+m) par[i] = i;
	rep(i, (int)edge.size()){
		int from = edge[i].second.first, to = edge[i].second.second;
		if(get_par(from) == get_par(to)) ans = ans + (long long)(edge[i].first);
		else par[get_par(from)] = get_par(to);
	}
	cout << ans << endl;
	return 0;
}