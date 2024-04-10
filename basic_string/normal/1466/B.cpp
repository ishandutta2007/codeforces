#include<bits/stdc++.h>
using namespace std;
int a[2],c[2],b[109999];
int main(){
	int T,n,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),a[0]=a[1]=0;
		for(i=1;i<=n;++i)scanf("%d",b+i);
		b[0]=-999;
		for(i=1;i<=n;++i){
			c[0]=a[0],c[1]=a[1],a[0]=a[1]=0;
			if(b[i-1]<b[i])a[0]=max(a[0],c[0]+1);
			else if(b[i-1]==b[i])a[0]=max(a[0],c[0]);
			if(b[i-1]+1<b[i])a[0]=max(a[0],c[1]+1);
			else if(b[i-1]+1==b[i])a[0]=max(a[0],c[1]);
			if(b[i-1]<b[i]+1)a[1]=max(a[1],c[0]+1);
			else if(b[i-1]==b[i]+1)a[1]=max(a[1],c[0]);
			if(b[i-1]+1<b[i]+1)a[1]=max(a[1],c[1]+1);
			else if(b[i-1]+1==b[i]+1)a[1]=max(a[1],c[1]);
		}
		cout<<max(a[0],a[1])<<'\n';
	}
	return 0;
}