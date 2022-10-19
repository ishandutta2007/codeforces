#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],n,t_case;
bool clr[maxn];
vector<int>e[maxn];
void dfs(int p,int fa){
	ri deg=0;
	for(ri i:e[p])
		if(i!=fa){
			clr[i]=clr[p]^1;
			dfs(i,p);
			++deg;
		}
	if(p==1)a[p]=deg;
	else a[p]=(clr[p]?-1:1)*(deg+1);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)a[i]=clr[i]=0,vector<int>().swap(e[i]);
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs(1,0);
		for(ri i=1;i<=n;++i)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}