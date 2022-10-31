#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int count[N][26]={0};
char s[N];
int main(){
	int n,i,j;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		for(i=0;s[i];i++){
			if(s[i]!='?') count[i][s[i]-'a']++;
		}
	}
	for(i=0;s[i];i++){
		char c='a';
		bool yes=false;
		for(j=0;j<26;j++){
			if(count[i][j]){
				if(yes) break;
				else{
					c='a'+j;
					yes=true;
				}
			}
		}
		if(j<26) putchar('?');
		else putchar(c);
	}
	putchar('\n');
	return 0;
}