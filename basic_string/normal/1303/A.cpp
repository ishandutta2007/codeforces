#include<bits/stdc++.h>
using namespace std;
char c[109];
int main(){
	int t,i,p,q,l,s;
	scanf("%d",&t);
	while(t--){
		scanf("%s",c),l=strlen(c),s=0;
		for(i=0;i<l;++i)if(c[i]=='1')break;
		p=i;
		if(p==l){
			printf("%d\n",0);
			continue;
		}
		for(i=l-1;i>=0;--i)if(c[i]=='1')break;
		q=i;
		for(i=p;i<=q;++i)if(c[i]=='0')++s;
		printf("%d\n",s);
	}
	return 0;
}//