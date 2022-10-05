#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009];
int main(){
	int n,m,i,j,k;
	long long s=0;
	cin>>n>>m;
	for(i=1;i<=m;++i)cin>>a[i],s+=a[i];
	if(s<n)puts("-1");
	else{
		j=n;
		for(i=m;i;--i)j=min(j-1,n-a[i]),b[i]=j+1;
		if(j<0)puts("-1");
		else{
			i=1;
			if(b[i]>1){
				b[i]=1;
				while(i<n&&b[i+1]-b[i]>a[i])b[i+1]=b[i]+a[i],++i;
			}
			for(i=1;i<=m;++i)printf("%d ",b[i]);
		}
	}
	return 0;
}