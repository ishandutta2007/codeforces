#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[N],b[N],c0[N],c1[N];
int main(){
	int T,n,i,j,k,l;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
		sort(b+1,b+n+1);
		for(i=1;i<=n;++i){
			if(i&1)++c0[a[i]];
			else ++c1[a[i]];
		}
		for(i=1;i<=n;++i){
			if(i&1)--c0[b[i]];
			else --c1[b[i]];
		}
		for(i=1;i<=n;++i)if(c0[a[i]]||c1[a[i]]){puts("NO");goto gg;}
		puts("YES");
		gg:; 
		for(i=1;i<=n;++i)c0[a[i]]=c1[a[i]]=0;
	}
	return 0;
}