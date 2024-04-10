#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
bitset<N>b[26],u;
char s[N],y[N];
int main(){
	int n,q,o,i,j,k,l;
	char c;
	scanf("%s%d",s+1,&q),n=strlen(s+1);
	for(i=1;i<=n;++i)b[s[i]-'a'][i]=1;
	while(q--){
		scanf("%d%d",&o,&i);
		if(o==1)scanf(" %c",&c),b[s[i]-'a'][i]=0,s[i]=c,b[c-'a'][i]=1;
		else{
			scanf("%d%s",&j,y+1),l=strlen(y+1),k=j-l+1;
			if(k<i){puts("0");continue;}
			u.set(),u>>=N-1-k+i;
			for(k=1;k<=l;++i,++k)u&=b[y[k]-'a']>>i;
			cout<<u.count()<<'\n';
		}
	}
	return 0;
}