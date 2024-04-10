#include<cstdio>
#include<cstring>
#define N 100100
using namespace std;
int trie[N][26];
int cnt=1;
char s[N];
bool check(int now,bool win){
	bool flag=false;
	for(int i=0;i<26;i++){
		if(trie[now][i]==-1) continue;
		if(!check(trie[now][i],win)) return true;
		flag=true;
	}
	if(flag) return false;
	return !win;
}		
int main(){
	int n,k,nlen,i,j,now;
	memset(trie,-1,sizeof(trie));
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%s",s);
		now=0;
		for(j=0;j<s[j];j++){
			if(trie[now][s[j]-'a']==-1){
				trie[now][s[j]-'a']=cnt;
				now=cnt++;
			}
			else now=trie[now][s[j]-'a'];
		}
	}
	bool canwin=check(0,true);
	bool canlose=check(0,false);
	if(canwin&&canlose){
		printf("First\n");
	}
	else if(!canwin&&!canlose){
		printf("Second\n");
	}
	else if(canwin&&!canlose){
		if(k&1) printf("First");
		else printf("Second");
	}
	else{
		printf("Second");
	}
	return 0;
}