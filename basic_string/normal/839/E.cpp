#include<bits/stdc++.h>
using namespace std;
const int N=43;
bool e[N][N];
int a[N],n,s[N];
int calc(){
	int i,j,k,t=0;
	for(i=1;i<=n;++i){
		j=a[i];
		for(k=1;k<=t;++k)if(!e[s[k]][j])goto gg;
		s[++t]=j;
		gg:;
	}
	return t;
}
int main(){
	int o,i,j,k,ans=0,now,w;
	double T;
	cin>>n>>o;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)cin>>e[i][j];
	for(i=1;i<=n;++i)a[i]=i;
	while(clock()<CLOCKS_PER_SEC*1.8){
		random_shuffle(a+1,a+n+1),now=calc(),ans=max(ans,now);
		for(T=100;T>0.01;T*=0.995){
			i=rand()%n+1,j=rand()%n+1,swap(a[i],a[j]),w=calc();
			if(w>now||exp((w-now)/T)*RAND_MAX>rand())now=w,ans=max(ans,w);
			else swap(a[i],a[j]);
		}
	}
	printf("%.9lf",o*o*0.5*(ans-1)/ans);
	return 0;
}