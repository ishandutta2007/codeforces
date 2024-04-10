#include<bits/stdc++.h>
using namespace std;
const int N=2009;
int l[N],r[N],u[N],d[N];
char s[N][N];
int main(){
	int n,m,i,j,k;
	long long w=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;l[i++]=j-1)for(j=1;s[i][j]=='.'&&j<m;++j);
	for(i=1;i<=n;r[i++]=j+1)for(j=m;s[i][j]=='.'&&j>1;--j);
	for(i=1;i<=m;d[i++]=j-1)for(j=1;s[j][i]=='.'&&j<n;++j);
	for(i=1;i<=m;u[i++]=j+1)for(j=n;s[j][i]=='.'&&j>1;--j);
	for(i=2;i<n;++i)for(j=2;j<m;++j)w+=(l[i]>=j&&d[j]>=i)+(l[i]>=j&&u[j]<=i)+(r[i]<=j&&d[j]>=i)+(r[i]<=j&&u[j]<=i);
	for(i=2;i<m;++i)for(j=2,k=0;j<n;++j){
		if(s[j][i]=='#')k=0;
		if(l[j]>=i)w+=k,++k;
	}
	for(i=2;i<m;++i)for(j=2,k=0;j<n;++j){
		if(s[j][i]=='#')k=0;
		if(r[j]<=i)w+=k,++k;
	}
	for(i=2;i<n;++i)for(j=2,k=0;j<m;++j){
		if(s[i][j]=='#')k=0;
		if(d[j]>=i)w+=k,++k;
	}
	for(i=2;i<n;++i)for(j=2,k=0;j<m;++j){
		if(s[i][j]=='#')k=0;
		if(u[j]<=i)w+=k,++k;
	}
	for(i=2;i<m;++i)for(j=2,k=0;j<n;++j){
		if(s[j][i]=='#')k=0;
		if(l[j]>=i)w+=k;
		if(r[j]<=i)++k;
	}
	for(i=2;i<m;++i)for(j=2,k=0;j<n;++j){
		if(s[j][i]=='#')k=0;
		if(r[j]<=i)w+=k;
		if(l[j]>=i)++k;
	}
	for(i=2;i<n;++i)for(j=2,k=0;j<m;++j){
		if(s[i][j]=='#')k=0;
		if(d[j]>=i)w+=k;
		if(u[j]<=i)++k;
	}
	for(i=2;i<n;++i)for(j=2,k=0;j<m;++j){
		if(s[i][j]=='#')k=0;
		if(u[j]<=i)w+=k;
		if(d[j]>=i)++k;
	}
	for(i=3;i<n;++i)w-=max(0,min(l[i],l[i-1])-1)+max(0,m-max(r[i],r[i-1]));
	for(i=3;i<m;++i)w-=max(0,min(d[i],d[i-1])-1)+max(0,n-max(u[i],u[i-1]));
	for(i=2;i<n;++i)w+=r[i]-l[i]<2;
	for(i=2;i<m;++i)w+=u[i]-d[i]<2;
	printf("%lld",w);
	return 0;
}