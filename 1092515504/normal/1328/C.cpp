#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[50010],s1[50010],s2[50010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s),s1[n]=s2[n]='\0';
		bool maxed=false;
		for(int i=0;i<n;i++){
			if(!maxed){
				if(s[i]=='0')s1[i]=s2[i]='0';
				if(s[i]=='1')s1[i]='1',s2[i]='0',maxed=true;
				if(s[i]=='2')s1[i]=s2[i]='1';				
			}else s1[i]='0',s2[i]=s[i];
		}
		printf("%s\n%s\n",s1,s2);
	}
	return 0;
}