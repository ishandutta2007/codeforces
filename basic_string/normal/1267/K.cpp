#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c[23][23];
int f[23];
int main(){
	int i,j,k,t;
	ll a,s,p;
	scanf("%d",&t);
	c[0][0]=1;
	for(i=1;i<21;++i){
		c[i][0]=1;
		for(j=1;j<=i;++j)c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	while(t--){
		memset(f,0,sizeof(f));
		scanf("%lld",&a),i=2,s=p=1;
		while(a)++f[a%i],a/=i,++i;
		k=i;
		for(i-=2,j=1;i>=0;--i,++j){
			if(!i)--j;
			s*=c[j][f[i]],j-=f[i];
		}
		i=k-1,--f[0];
		if(f[k-2])p=0;
		else for(i-=2,j=1;i>=0;--i,++j){
			if(!i)--j;
			p*=c[j][f[i]],j-=f[i];
		}
		printf("%lld\n",s-p-1);
	}
	return 0;
}