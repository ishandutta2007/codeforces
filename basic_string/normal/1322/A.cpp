#include<bits/stdc++.h>
using namespace std;
char s[1000009];
int main(){
	int n,i,j=0,k=0,l=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;++i)if(s[i]=='(')++j;
	if(j!=(n-j)){
		puts("-1");
		return 0;
	}
	j=0;
	for(i=1;i<=n;++i){
		if(s[i]=='('){
			++j;
			if(j==0)k+=i-l,l=i;
		}else{
			--j;
			if(j==0)l=i;
		}
	}
	printf("%d",k);
	return 0;
}//