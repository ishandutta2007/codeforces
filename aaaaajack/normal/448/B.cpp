#include<cstdio>
char s[1000],t[1000];
int cnts[26]={0},cntt[26]={0};
using namespace std;
int main(){
	scanf("%s %s",s,t);
	int i,j;
	bool tree=false,aut=true,arr=true;
	for(i=0;s[i];i++) cnts[s[i]-'a']++;
	for(i=0;t[i];i++) cntt[t[i]-'a']++;
	for(i=0;i<26;i++){
		if(cnts[i]<cntt[i]) tree=true;
		if(cnts[i]!=cntt[i]) arr=false;
	}
	for(i=0,j=0;s[i];i++){
		if(t[j]==s[i]) j++;
	}
	if(t[j]) aut=false;
	if(tree) printf("need tree\n");
	else if(arr) printf("array\n");
	else if(aut) printf("automaton\n");
	else printf("both\n");
	return 0;
}