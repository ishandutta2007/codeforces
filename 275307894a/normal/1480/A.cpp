#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,t;
char s[100039];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);n=strlen(s+1);
		for(i=1;i<=n;i++){
			if(i&1){
				if(s[i]=='a') s[i]='b';
				else s[i]='a';
			}
			else{
				if(s[i]=='z') s[i]='y';
				else s[i]='z';
			}
		}
		printf("%s\n",s+1);
	}
}