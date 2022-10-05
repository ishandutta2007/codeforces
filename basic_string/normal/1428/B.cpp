#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
char s[N];
int main(){
	int T,i,j,k,l,n,t,w;
	bool f1,f2;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s);
		f1=f2=0;
		for(i=0;i<n;++i)if(s[i]=='>')f1=1;else if(s[i]=='<')f2=1;
		if(!f1||!f2)printf("%d\n",n);
		else{
			w=0;
			for(i=1;i<n;++i)if(s[i-1]=='-'||s[i]=='-')++w;
			if(s[0]=='-'||s[n-1]=='-')++w;
			printf("%d\n",w);
		}
	}
	return 0;
}