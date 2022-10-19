#include<bits/stdc++.h>
using namespace std;
int n,m,res;
char s[100100],t[10];
bool val(int x){
	if(x>=3&&s[x-2]=='a'&&s[x-1]=='b'&&s[x]=='c')return true;
	if(x>=2&&x+1<=n&&s[x-1]=='a'&&s[x]=='b'&&s[x+1]=='c')return true;
	if(x+2<=n&&s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c')return true;
	return false;
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n-2;i++)if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')res++;
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		res-=val(x);
		scanf("%s",t),s[x]=t[0];
		res+=val(x);
		printf("%d\n",res);
	}
	return 0;
}