#include<bits/stdc++.h>
using namespace std;
int n,q;
int bit[10010];
void ADD(int x,int z){while(x<=(n<<1))bit[x]+=z,x+=x&-x;}
int SUM(int x){int ret=0;while(x)ret+=bit[x],x-=x&-x;return ret;}
int t[10100][5010];
void ADD(int x,int y,int z){for(int i=x;i<=(n<<1);i+=i&-i)for(int j=y;j;j-=j&-j)t[i][j]+=z;}
int SUM(int x,int y){int ret=0;for(int i=x;i;i-=i&-i)for(int j=y;j<=n;j+=j&-j)ret+=t[i][j];return ret;}
int tp[100100],x[100100],y[100100],l[100100];
int res[100100];
void work(){
	for(int i=1;i<=q;i++){
		if(tp[i]==5)ADD(x[i]+y[i],x[i],1),ADD(x[i]+y[i]+l[i]+1,x[i],-1);
		if(tp[i]==0)res[i]-=SUM(x[i]+y[i],x[i]+1);
	}
//	for(int i=1;i<=q;i++)if(tp[i]==0)printf("%d ",res[i]);puts("");
	memset(t,0,sizeof(t));
	for(int i=1;i<=q;i++){
		if(tp[i]==5)ADD(x[i]+y[i],y[i],1),ADD(x[i]+y[i]+l[i]+1,y[i],-1);
		if(tp[i]==0)res[i]-=SUM(x[i]+y[i],y[i]+1);
	}
//	for(int i=1;i<=q;i++)if(tp[i]==0)printf("%d ",res[i]);puts("");
	memset(t,0,sizeof(t));
	for(int i=1;i<=q;i++){
		if(tp[i]==5)ADD(x[i]+y[i],1),ADD(x[i]+y[i]+l[i]+1,-1),tp[i]=-1;
		if(tp[i]==0)res[i]+=SUM(x[i]+y[i]);
	}
//	for(int i=1;i<=q;i++)if(tp[i]==0)printf("%d ",res[i]);puts("");
	memset(bit,0,sizeof(bit));
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&tp[i]);
		if(tp[i]==1)scanf("%d%d%d%d",&tp[i],&x[i],&y[i],&l[i]);
		else tp[i]=0,scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=q;i++)if(tp[i]==1)tp[i]=5;
	work();
	for(int i=1;i<=q;i++){
		if(tp[i]==2)y[i]=n-y[i]+1,tp[i]=5;
		if(tp[i]==0)y[i]=n-y[i]+1;
	}
	work();
	for(int i=1;i<=q;i++){
		if(tp[i]==3)x[i]=n-x[i]+1,tp[i]=5;
		if(tp[i]==0)x[i]=n-x[i]+1,y[i]=n-y[i]+1;
	}
	work();
	for(int i=1;i<=q;i++){
		if(tp[i]==4)x[i]=n-x[i]+1,y[i]=n-y[i]+1,tp[i]=5;
		if(tp[i]==0)y[i]=n-y[i]+1;
	}
	work();
	for(int i=1;i<=q;i++)if(tp[i]==0)printf("%d ",res[i]);puts("");
	return 0;
}