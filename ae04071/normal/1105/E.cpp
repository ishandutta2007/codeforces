#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;

int n,m,adj[40][40],ci;
map<string, int> tr;

int sm[40],lm[40],ans[1<<20],ls[1<<20];

int get(string s) {
	if(tr.count(s)) return tr[s];
	else return tr[s]=ci++;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(m==1) {
		puts("1"); return 0;
	}
	
	lli v=0;
	for(int i=0;i<n;i++) {
		int a;
		string s;
		cin >> a;
		if(a==1) {
			for(int i=0;i<m;i++) for(int j=0;j<m;j++) if(i!=j && ((v>>i&1)&(v>>j&1))) {
				adj[i][j] = adj[j][i] = 1;
			}
			v=0;
		} else {
			cin >> s;
			v |= 1ll << get(s);
		}
	}
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) if(i!=j && ((v>>i&1)&(v>>j&1))) {
		adj[i][j] = adj[j][i] = 1;
	}


	int md=m/2;
	for(int i=0;i<m/2;i++) {
		int t=0;
		for(int j=0;j<m/2;j++) if(adj[i][j]) t|=1<<j;
		sm[i] = t;
	}
	for(int i=0;i<m-m/2;i++) {
		int t=0;
		for(int j=0;j<m-m/2;j++) if(adj[md+i][md+j]) t|=1<<j;
		sm[md+i] = t;
	}
	for(int i=0;i<m-md;i++) {
		int t=0;
		for(int j=0;j<md;j++) if(adj[md+i][j]) t|=1<<j;
		lm[md+i] = t;
	}
	
	int bas = (1<<md)-1;
	for(int s=0;s<1<<(m-md);s++) {
		for(int i=0;i<(m-md);i++) if(!(s>>i&1)) {
			ls[s^(1<<i)] |= ls[s] | lm[i+md];
		}
	}

	for(int s=0;s<1<<(md);s++) {
		int f=1,c=0;
		for(int i=0;i<md;i++) if(s>>i&1) {
			if(s & sm[i]) {
				f=0;
				break;
			}
			c++;
		}
		if(f) {
			ans[s] = c;
		}
	}

	int res=0;
	for(int s=0;s<1<<md;s++) {
		for(int i=0;i<md;i++) if(!(s>>i&1)) ans[s|(1<<i)] = max(ans[s|(1<<i)],ans[s]);
		res = max(res,ans[s]);
	}

	for(int s=0;s<1<<(m-md);s++) {
		int f=1,c=0;
		for(int i=0;i<(m-md);i++) if(s>>i&1) {
			if(s & sm[md+i]) {
				f=0;
				break;
			}
			c++;
		}
		if(f) {
			res = max(res,c);
			res = max(res, c + ans[bas^ls[s]]);
		}
	}
	cout << res;
	

	return 0;
}