#include<bits/stdc++.h>
using namespace std;
int a[100009],ans,ans2,b[100009],c[200099],*ct=c+100009,D[200099],*u=D+100009;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,d,i,j,k,l;
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i];
	for(d=-203;d<=203;++d){
		for(j=1;j<=n;++j)b[j]=a[j]-j*d;
		sort(b+1,b+n+1);
		for(j=2,l=1;j<=n;++j){
			if(b[j]!=b[j-1]){
				ans=max(ans,l);
				l=1;
			}else ++l;
		}
		ans=max(ans,l);
	}
	for(i=1;i<=n;++i){
		for(j=min(n,i+503);j>i;--j){
			if((a[j]-a[i])%(j-i)==0)
			{
				k=(a[j]-a[i])/(j-i);
				if(u[k]<i)u[k]=i,ct[k]=0;
				ans2=max(ans2,++ct[k]);
			}
		}
	}
	ans=max(ans,ans2+1);
	cout<<n-ans;
}