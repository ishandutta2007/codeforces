#include<bits/stdc++.h>
using namespace std;
int T,n,a[110],b[110],c[110],p[110];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)scanf("%d",&b[i]);
		for(int i=0;i<n;i++)scanf("%d",&c[i]);
		p[0]=a[0];
		for(int i=1;i+1<n;i++){
			if(p[i-1]!=a[i])p[i]=a[i];
			else if(p[i-1]!=b[i])p[i]=b[i];
			else if(p[i-1]!=c[i])p[i]=c[i];
		}
		if(p[n-2]!=a[n-1]&&p[0]!=a[n-1])p[n-1]=a[n-1];
		else if(p[n-2]!=b[n-1]&&p[0]!=b[n-1])p[n-1]=b[n-1];
		else if(p[n-2]!=c[n-1]&&p[0]!=c[n-1])p[n-1]=c[n-1];
		for(int i=0;i<n;i++)printf("%d ",p[i]);puts("");
	}
	return 0;
}