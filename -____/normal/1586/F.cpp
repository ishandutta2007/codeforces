#include<bits/stdc++.h>
using namespace std;
const int N = 1111;
int n,k,m,a[N][N];
void solve(int l,int r,int t){
	if(l==r)
		return;
	m=max(m,t);
	int i,j,u=(r-l)/k+1;
	for(i=l;i<=r;i++)
		for(j=i+1;j<=r;j++)
			if((i-l)/u!=(j-l)/u)
				a[i][j]=t;
	for(i=l;i<=r;i+=u)
		solve(i,min(i+u-1,r),t+1);
}
int main(){
	int i,j,x,y;
	scanf("%d%d",&n,&k);
	solve(1,n,1);
	printf("%d\n",m);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			printf("%d ",a[i][j]);
	return 0;
}