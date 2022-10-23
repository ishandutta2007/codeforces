#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int l,r,f[40][40],k,_,o,n,x[10000],y[10000],m;
int main(){
	scanf("%d%d",&l,&r);
	printf("YES\n");
	if(l==r){
		printf("2 1\n1 2 %d\n",l);
		return 0;
	}
	k=r-l+1;
	_=25;
	while(k<(1<<_))--_;
	n=2;
	f[1][2]=1;
	o=1;
	for(int i=_;i>=0;--i){
		int O=(k>>i);
		if((O<<i)!=k)++O;
		if(o==O) continue;
		if(o*2==O){
			for(int j=1;j<n;++j)if(f[j][n])f[j][n+1]=f[j][n];
			f[n][n+1]=o;
		}
		else{
			for(int j=1;j<n;++j)if(f[j][n])f[j][n+1]=f[j][n];
			f[1][n]=0;
			f[n][n+1]=o-1;
		}
		++n;
		o=O;
	}
	if(l>1){
		f[n][n+1]=l-1;
		++n;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)if(f[i][j])++m,x[m]=i,y[m]=j;
	}
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;++i)printf("%d %d %d\n",x[i],y[i],f[x[i]][y[i]]);
    return 0;
}