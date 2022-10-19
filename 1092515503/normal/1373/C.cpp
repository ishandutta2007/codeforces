#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,S,res,cur,mn;
char s[1001000];
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%s",s),S=strlen(s),cur=mn=res=0;
		for(int i=0;i<S;i++){
			if(s[i]=='-')cur--;
			else cur++;
			if(cur<mn)res+=i+1,mn=cur;
		}
		printf("%I64d\n",res+S);
	}
	return 0;
}