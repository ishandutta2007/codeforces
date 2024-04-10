#include<bits/stdc++.h>
using namespace std;
char s[1009];
int main(){
	int i,j,k,u=0,v=0,n;
	scanf("%s",s+1),n=strlen(s+1);
	j=n+1;
	for(i=1;i<=n;++i)if(s[i]=='('){j=i;break;}
	k=0;
	for(i=n;i;--i)if(s[i]==')'){k=i;break;}
	if(j>k){puts("0");return 0;}
	printf("%d\n",1);
	for(i=1;i<=n;++i)if(s[i]==')')++v;
	for(i=1;i<=n;++i){
		if(s[i]=='(')++u;
		else if(s[i]==')')--v;
		if(u==v)break;
	}
	printf("%d\n",u+v);
	for(j=1;j<=i;++j)if(s[j]=='(')printf("%d ",j);
	for(j=i+1;j<=n;++j)if(s[j]==')')printf("%d ",j);
	return 0;
}//