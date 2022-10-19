#include<bits/stdc++.h>
using namespace std;
int f[1<<22],fr[1<<22],id[1<<22],n,m,sta[22],mxn;
stack<int>s;
int main(){
	scanf("%d%d",&n,&m),mxn=(1<<n),memset(f,0x3f3f3f,sizeof(f));
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),x--,y--,sta[x]|=(1<<y),sta[y]|=(1<<x);
	if(m*2==n*(n-1)){puts("0");return 0;}
	for(int i=0;i<n;i++)f[1<<i]=0;
	for(int x=1;x<mxn;x++)for(int i=0;i<n;i++){
		if(!(x&(1<<i)))continue;
		int y=x|sta[i];
		if(y==x)continue;
		if(f[y]>f[x]+1)f[y]=f[x]+1,fr[y]=x,id[y]=i;
	}
	printf("%d\n",f[mxn-1]);
	int x=mxn-1;
	while(__builtin_popcount(x)!=1)s.push(id[x]),x=fr[x];
	while(!s.empty())printf("%d ",s.top()+1),s.pop();
	return 0;
}