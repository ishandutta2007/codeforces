#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int a[N],b[N],n,T,m;
map<int,int> in;
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		in.clear();
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i) scanf("%d",&a[i]),in[a[i]]=1;
		for(i=1;i<=m;++i) scanf("%d",&b[i]);
		for(i=1;i<=m;++i) if(in[b[i]]) break;
		i>m?puts("NO"):printf("YES\n1 %d\n",b[i]);
	}
	return 0;
}