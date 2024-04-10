#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char s[N],y[N];
bitset<N>b[26],u;
int a[N];
int main(){
	int n,q,i,k,l,o,t;
	scanf("%s%d",s+1,&q),n=strlen(s+1);
	for(i=1;i<=n;++i)b[s[i]-'a'][i]=1;
	while(q--){
		if(scanf("%d%s",&k,y+1),l=strlen(y+1),l>n){puts("-1");continue;} 
		u.set(),u>>=N-1-n+l,t=0;
		for(i=1;i<=l;++i)u&=b[y[i]-'a']>>i;
		for(i=u._Find_first();i!=N;i=u._Find_next(i))a[++t]=i;
		if(t<k)puts("-1");else{
			for(o=N,i=k;i<=t;++i)o=min(o,a[i]-a[i-k+1]);
			printf("%d\n",o+l);
		}
	}
	return 0;
}