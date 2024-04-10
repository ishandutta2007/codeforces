#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
const int N=2e5+3,M=7003;
char s[N];
bool a[N],b[N];
unsigned f[33][M],g[33][M];
int main(){
	int i,j,k,l,o,q;
	scanf("%s",s),l=strlen(s);
	for(i=0;i<l;++i)a[i]=s[i]=='1';
	for(i=0;i<32;++i){
		for(j=i,o=0;j<l;j+=32,++o){
			for(k=0;k<32;++k)f[i][o]=f[i][o]*2+a[k+j];
		}
	}
	scanf("%s",s),l=strlen(s);
	for(i=0;i<l;++i)b[i]=s[i]=='1';
	for(i=0;i<32;++i){
		for(j=i,o=0;j<l;j+=32,++o){
			for(k=0;k<32;++k)g[i][o]=g[i][o]*2+b[k+j];
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&j,&k,&l),o=0;
		unsigned*u=f[j&31]+(j>>5),*v=g[k&31]+(k>>5);
		for(i=31;i<l;i+=32,++u,++v)o+=__builtin_popcount(*u^*v);
		printf("%d\n",o+__builtin_popcount((*u^*v)&-((1u<<31-(l&31))<<1)));
	}
	return 0;
}