#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],c[maxn],d[maxn],m,n,t_case;
vector<int>to[maxn];
void dfs(int p){
	if(p)printf("%d ",p);
	sort(to[p].begin(),to[p].end(),[&](int x,int y){return to[x].size()<to[y].size();});
	for(ri i:to[p])dfs(i);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		to[0].clear();
		for(ri i=1;i<=n;++i)scanf("%d",b+i),to[i].clear();
		c[1]=b[1];
		for(ri i=2;i<=n;++i)c[i]=min(c[i-1],b[i]);
		d[n+1]=0;
		for(ri i=n;i;--i)d[i]=max(d[i+1],b[i]);
		ri k=0;
		for(ri i=1;i<=n;++i)
			if(c[i]>i&&d[i+1]<=i)
				k=i;
		printf("%d\n",k);
		vector<vector<int>>e;
		for(ri i=1;i<=n;++i){
			if(1<=b[i]&&b[i]<=n)to[b[i]].push_back(i);
			else to[0].push_back(i);
		}
		dfs(0);
		putchar(10);
	}
	return 0;
}