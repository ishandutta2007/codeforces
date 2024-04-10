#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int t[N*2];
char s[N];
int main(){
	int T,i,n,o,*p=t+N;
	for(scanf("%d",&T);T--;puts("")){
		scanf("%s",s),n=strlen(s);
		for(i=-n;i<=n;++i)p[i]=0;
		for(i=o=0;i<n;++i)if(s[i]=='1')++p[o++];else ++p[--o];
		for(i=o=0;i<n;++i)if(p[o-1]&&(!p[o]||p[o-1]>1))--p[--o],putchar('0');else --p[o++],putchar('1'); 
	}
	return 0;
}