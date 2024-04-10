#include<bits/stdc++.h>
using namespace std;
int T,n,sum[2][2],res;
char s[100100],t[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,s,t),res=n+1;
		memset(sum,0,sizeof(sum));for(int i=0;i<n;i++)sum[s[i]-'0'][t[i]-'0']++;
		if(sum[0][1]==sum[1][0])res=min(res,sum[0][1]+sum[1][0]);
		if(sum[1][1]==sum[0][0]+1)res=min(res,sum[0][0]+sum[1][1]);
		printf("%d\n",res>n?-1:res);
	}
	return 0;
}