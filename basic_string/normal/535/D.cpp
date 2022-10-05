#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,P=1e9+7;
char s[N];
int p[N],f[N];
bool v[N];
int main(){
	int n,m,l,i,j,k;
	scanf("%d%d%s",&n,&m,s+1),l=strlen(s+1);
	for(i=2,j=0;i<=l;++i){
		while(j&&s[i]!=s[j+1])j=p[j];
		if(s[i]==s[j+1])p[i]=++j;
	}
	for(i=l;i;i=p[i])v[i]=1;
	if(m){scanf("%d",&j);
	for(;++f[j],--f[j+l],--m;j=i)if(scanf("%d",&i),(k=l-i+j)>0&&!v[k])return puts("0"),0;
	}for(i=j=1;i<=n;++i)if(!(f[i]+=f[i-1]))j=j*26ll%P;
	printf("%d",j);
	return 0;
}