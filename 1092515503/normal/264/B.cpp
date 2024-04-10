#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,pri[N+10],pre[N+10],mx[N+10],f[N+10],res;
void ural(){
	for(int i=2;i<=N;i++){
		if(!pri[i])pri[++pri[0]]=i,pre[i]=pri[0];
		for(int j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			pri[i*pri[j]]=true,pre[i*pri[j]]=j;
			if(!(i%pri[j]))break;
		}
	}
}
int main(){
	scanf("%d",&n),ural();
	for(int i=1,x,t;i<=n;i++){
		scanf("%d",&x),f[i]=1;
		t=x;
		while(t!=1)f[i]=max(f[i],mx[pre[t]]+1),t/=pri[pre[t]];
		t=x;
		while(t!=1)mx[pre[t]]=f[i],t/=pri[pre[t]];
		res=max(res,f[i]);
	}
	printf("%d\n",res);
	return 0;
}