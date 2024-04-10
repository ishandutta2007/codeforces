#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int tot[256];
char s[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s),m=strlen(s);
			for(int j=0;j<m;j++)tot[s[j]-'a']++;
		}
		bool ok=true;
		for(int i=0;i<26;i++)ok&=!(tot[i]%n),tot[i]=0;
		puts(ok?"YES":"NO");
	}
	return 0;
}