#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>
#include <ctime>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define ALL(x) x.begin(),x.end()

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m,arr[1<<22],ic[1<<22],pa[1<<22],chk[1<<22];
int vis[1<<22],has[1<<22];

int inv(int val) {
	int res = ~val;
	res &= ((1<<n)-1);
	return res;
}
int find(int cur) {
	return cur==pa[cur] ? cur : pa[cur]=find(pa[cur]);
}
void merge(int u,int v) {
	int pu=find(u),pv=find(v);
	pa[pv]=pu;
}
void bfs_has() {
	for(int i=0;i<(1<<n);i++) {
		has[i] |= chk[i];
		for(int j=0;j<n;j++) if(!(i & (1<<j))) {
			int nx=i ^ (1<<j);
			has[nx] |= has[i];
		}
	}
}
void bfs() {
	for(int i=(1<<n)-1;i>=0;i--) {
		for(int j=0;j<n;j++) if(i & (1<<j)) {
			int nx=i ^ (1<<j);
			if(chk[i] && has[nx]) {
				chk[nx]=1; merge(i,nx);
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d",arr+i);
	for(int i=0;i<1<<n;i++) pa[i]=i;
	for(int i=0;i<m;i++) {
		chk[arr[i]]=1;
	}
	bfs_has();
	fill(chk,chk+(1<<n),0);
	for(int i=0;i<m;i++) {
		chk[inv(arr[i])] = 1;
		merge(arr[i],inv(arr[i]));
	}
	bfs();
	fill(chk,chk+(1<<n),0);

	int cnt=0;
	for(int i=0;i<m;i++) chk[find(arr[i])] = 1;
	for(int i=0;i<(1<<n);i++) if(chk[find(i)]) {
		cnt++;
		chk[find(i)]=0;
	}
	printf("%d\n",cnt);
	
	return 0;
}