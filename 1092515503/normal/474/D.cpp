#include<bits/stdc++.h>
using namespace std;
const int N=100000;
const int MOD=1e9+7;
int _1,k,f[N+10],t1,t2;
int main(){
	scanf("%d%d",&_1,&k),f[0]=1;
	for(int i=1;i<=N;i++){
		f[i]+=f[i-1],f[i]%=MOD;
		if(i>=k)f[i]+=f[i-k],f[i]%=MOD;
	}
	for(int i=1;i<=N;i++)f[i]+=f[i-1],f[i]%=MOD;
	while(_1--)scanf("%d%d",&t1,&t2),printf("%d\n",(f[t2]-f[t1-1]+MOD)%MOD);
	return 0;
}