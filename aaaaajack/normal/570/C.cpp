#include<cstdio>
#include<map>
#define N 300100
using namespace std;
char s[N];
int main(){
	int n,m,len=0,now=0;
	int pos;
	char c;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=0;s[i];i++){
		if(s[i]=='.') len++;
		else if(len){
			now+=len-1;
			len=0;
		}
	}
	if(len) now+=len-1;
	while(m--){
		scanf("%d %c",&pos,&c);
		pos--;
		int lf=pos>0&&s[pos-1]=='.';
		int rf=pos<n-1&&s[pos+1]=='.';
		if(s[pos]=='.'&&c!='.'){
			now-=lf+rf;
		}
		else if(s[pos]!='.'&&c=='.'){
			now+=lf+rf;
		}
		s[pos]=c;
		printf("%d\n",now);
	}
	return 0;
}