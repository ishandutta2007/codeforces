#include<bits/stdc++.h>
using namespace std;
int T,n,a[30];
char s[200100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),n=strlen(s);
		for(int i=0;i<n;i++)a[s[i]-'a']++;
		for(int i=0;i<n;i++)if(!--a[s[i]-'a']){printf("%s\n",s+i);break;}
		for(int i=0;i<26;i++)a[i]=0;
	}
	return 0;
}