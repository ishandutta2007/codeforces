#include<cstdio>
using namespace std;
int n,m,k,x,y,z,p,d[10039],dh,l[10039],ans[10039],head,flag,pl[10039];
inline int pow(int x,int y){
	if(y==1) return 10;
	else return 100;
}
inline void dfs(int x,int sum,int osum){
	if(flag) return;
	if(x==dh+1){
		if(!sum&&!osum&&head){
			printf("Yes\n");
			printf("%d\n",head);
			register int i;
			for(i=1;i<=head;i++) printf("%d ",ans[i]);
			flag=1;
		}
		return;
	}
	ans[++head]=pl[x];
	dfs(x+1,(sum*pow(10,l[x])+d[x])%p,osum^d[x]);
	ans[head--]=0;
	dfs(x+1,sum,osum);
}
int main(){
	register int i;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(x<=26) d[++dh]=x,pl[dh]=i;
	}
	for(i=1;i<=dh;i++){
		x=d[i];
		while(x) l[i]++,x/=10;
	}
	dfs(1,0,0);
	if(!flag) printf("No\n");
}