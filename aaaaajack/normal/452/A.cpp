#include<cstdio>
#include<cstring>
using namespace std;
char name[10][20]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main(){
	int n,i,j;
	char s[20];
	scanf("%d%s",&n,s);
	for(i=0;i<8;i++){
		if(n!=strlen(name[i])) continue;
		for(j=0;j<n;j++){
			if(s[j]!='.'&&s[j]!=name[i][j]) break;
		}
		if(j==n) break;
	}
	puts(name[i]);
	return 0;
}