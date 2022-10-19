#include<bits/stdc++.h>
using namespace std;
int T,n,m,res;
char s[400100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s),m=n,res=0;
		int p=0;
		while(p<n-1&&s[p]==s[p+1])s[m++]=s[p++];
		s[m++]=s[p++];
		for(int l=p,r=p;r<m;l=r){
			while(r<m&&s[r]==s[l])r++;
			res+=(r-l)/3;
		}
		if(p==n)res=(n-1)/3+1;
//		for(int i=p;i<m;i++)printf("%c",s[i]);puts("");
		printf("%d\n",res);
	}
	return 0;
}