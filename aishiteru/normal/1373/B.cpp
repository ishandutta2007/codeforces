#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
il int Min(ct p,ct q){return p<q?p:q;}
int T,n;
char s[N];
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);
		it cn1=0,cn0=0,i;
		for(i=1;i<=n;++i)
			cn0+=s[i]=='0',cn1+=s[i]=='1';
		Min(cn0,cn1)&1?puts("DA"):puts("NET");
	}
	return 0;
}