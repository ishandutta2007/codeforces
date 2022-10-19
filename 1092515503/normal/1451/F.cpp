#include<bits/stdc++.h>
using namespace std;
int T,n,m,g[210];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n+m;i++)g[i]=0;
		for(int i=1;i<=n;i++)for(int j=1,x;j<=m;j++)scanf("%d",&x),g[n-i+m-j]^=x;
		bool ok=false;
		for(int i=0;i<n+m;i++)ok|=!!g[i];
		puts(ok?"Ashish":"Jeel");
	}
	return 0;
}