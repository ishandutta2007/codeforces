#include<bits/stdc++.h>
using namespace std;
int n,f[200100],mn[200100],mx[200100],res;
bool sd[200100];
int L1,L2,t1,t2;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x<=n&&y<=n||x>n&&y>n){puts("-1");return 0;}
		if(x>y)f[y]=x,sd[y]=false;
		else f[x]=y,sd[x]=true;
	}
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
	mn[1]=f[1];for(int i=2;i<=n;i++)mn[i]=min(mn[i-1],f[i]);
	mx[n]=f[n];for(int i=n-1;i;i--)mx[i]=max(mx[i+1],f[i]);
	L1=L2=2*n+1;
	for(int i=1;i<=n;i++){
		if(f[i]>max(L1,L2)){puts("-1");return 0;}
		if(L1>L2&&L2<f[i]||L1<=L2&&L1>=f[i])L1=f[i],t1+=sd[i],t2+=!sd[i];
		else L2=f[i],t1+=!sd[i],t2+=sd[i];
		if(mn[i]>mx[i+1])L1=L2=2*n+1,res+=min(t1,t2),t1=t2=0;
	}
	printf("%d\n",res);
	return 0;
}