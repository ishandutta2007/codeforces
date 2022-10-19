#include<bits/stdc++.h>
#define ll long long
#define N 1000015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define rep0(i, n) for (int i=0;i<(n); ++i)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int T, n, d, a[N], dis[N];
queue<int> q;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &d);
		rep0(i, n) scanf("%d", &a[i]);
		rep0(i, n) dis[i] = a[i] == 0 ? 0 : inf;
		rep0(i, n) if(!a[i]) q.push(i);
		while(!q.empty()) {
			int u = q.front();
			// printf("%d %d\n", u, dis[u]);
			q.pop();
			int v = (u + d) % n;
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		int res = *max_element(dis, dis + n);
		printf("%d\n", res == inf ? -1 : res);
	}	
	return 0;
}