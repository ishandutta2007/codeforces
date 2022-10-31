#include<cstdio>
#include<cstring>
using namespace std;
char s[200];
char t[20]="CODEFORCES";
int main(){
	scanf("%s",s);
	int i,slen=strlen(s),tlen=strlen(t),x=0,y=0;
	for(i=0;i<slen&&i<tlen;i++){
		if(s[i]==t[i]) x++;
		else break;
	}
	for(i=0;i<slen&&i<tlen;i++){
		if(s[slen-1-i]==t[tlen-1-i]) y++;
		else break;
	}
	if(x+y>=tlen) puts("YES");
	else puts("NO");
	return 0;
}