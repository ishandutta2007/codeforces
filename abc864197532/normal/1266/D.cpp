#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pli pair<lli,int> 
#define pil pair<int,lli> 

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector <pli> dis;
	fop (i,0,n) dis.eb(0,i);
	fop (i,0,m) {
		int a,b;
		lli c;
		cin >> a >> b >> c;
		a--, b--;
		dis[a].first -= c;
		dis[b].first += c;
	}
	sort(dis.begin(), dis.end());
	vector <pil> edge[n];
	int i=0, j=n-1, ans=0, u;
	long long v;
	while (j > i) {
		lli d = min(abs(dis[i].first), abs(dis[j].first));
		if (d > 0) {
			edge[dis[i].second].eb(dis[j].second, 1ll * d);
			dis[i].first += d;
			dis[j].first -= d;
			ans++;
		}
		if (dis[i].first == 0) i++;
		if (dis[j].first == 0) j--;
	}
	cout << ans << endl;
	fop (i,0,n) {
		fop (j,0,edge[i].size()) {
			tie(u,v) = edge[i][j];
			cout << i+1 << ' ' << u+1 << ' ' << v << endl;
		}
	}
}