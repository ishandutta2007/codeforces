#include<bits/stdc++.h>
using namespace std;
char s[1010];
bool flag[1010];
int len;
int main(){
	scanf("%s",&s),len=strlen(s);
	for(int i=0;i<len;i++){
		if(i+1!=len)printf("%d ",s[i]!=s[i+1]);
		else printf("%d ",s[i]=='a');
	}
	return 0;
}