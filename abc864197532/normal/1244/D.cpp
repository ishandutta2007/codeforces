#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	cin >> n;
	lli value[n][3];
	fop (i,0,n) cin >> value[i][0];
	fop (i,0,n) cin >> value[i][1];
	fop (i,0,n) cin >> value[i][2];
	vector <int> tree[n];
	fop (i,0,n-1) {
		int u,v;
		cin >> u >> v;
		tree[u-1].pb(v-1);
		tree[v-1].pb(u-1);
	}
	int v1=-1;
	fop (i,0,n) {
		if (tree[i].size()>2) {
			cout << -1 << endl;
			return 0;
		} if (tree[i].size()==1) {
			if (v1==-1) v1=i;
		}
	}
	int dis[n],k=0,t[3]={0,1,2};
	fop (i,0,n) dis[i]=-1;
	while (true) {
		dis[v1]=t[k%3];
		k++;
		if (k==n) break;
		fop (i,0,tree[v1].size()) {
			if (dis[tree[v1][i]]==-1) {
				v1=tree[v1][i];
				break;
			}
		}
	}
	lli ans[6],now=0;
	fop (i,0,6) ans[i]=0;
	do {
		fop (i,0,n) {
			ans[now]+=value[i][t[dis[i]]];
		}
		now++;
	} while (next_permutation(t,t+3));
	auto ansss=min_element(ans,ans+6);
	cout << *ansss << endl;
	fop (i,0,3) t[i]=i;
	fop (i,0,ansss-ans) {
		next_permutation(t,t+3);
	}
	fop (i,0,n) {
		cout << t[dis[i]]+1 << ' ';
	}
	cout << endl;
}