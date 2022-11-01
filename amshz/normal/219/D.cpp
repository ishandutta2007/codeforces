# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;
int a[xn], b[xn], d[xn], t[xn], n, ans;
pair <int, int> p;
vector <pair <int, int> > vec[xn];
map <int, int> mp;
bool mark[xn];

void dfs2(int v){
	mark[v] = true;
	for (int u=0; u<vec[v].size(); u++){
		if (mark[vec[v][u].first]) continue;
		if (b[vec[v][u].second]-1 == v) d[vec[v][u].first] = d[v]+1;
		else d[vec[v][u].first] = d[v]-1;
		dfs2(vec[v][u].first);
	}
}

void dfs(int v){
	mark[v] = true;
	for (int u=0; u<vec[v].size(); u++){
		if (mark[vec[v][u].first]) continue;
		if (b[vec[v][u].second]-1 == v) ans++;
		dfs(vec[v][u].first);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n-1; i++) cin >> a[i] >> b[i], p.first = a[i]-1, p.second = i, vec[b[i]-1].push_back(p), p.first = b[i]-1, vec[a[i]-1].push_back(p), t[a[i]-1]++;
	for (int i=0; i<n; i++){
		if (t[i] == 0){
			dfs2(i);
			int dx = 0;
			for (int j=0; j<n; j++) if (d[dx] < d[j]) dx = j;
			for (int j=0; j<n; j++) mark[j] = false;
			dfs(dx);
			cout << ans << endl;
			for (int j=0; j<n; j++) if (d[j] == d[dx]) cout << j+1 << ' ';
			cout << endl;
			return 0;
		}
	}
}