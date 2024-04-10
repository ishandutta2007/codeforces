/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[210];
int num[26];
void mina(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int j=0;j<26;j++)num[j]=0;
	for(int i=1;i<=n;i++)num[s[i]-'a']++;
	for(int i=1;i<=m;i++){
		int j;
		for(j=0;j<n/m;j++){if(!num[j])break;num[j]--;}
		putchar('a'+j);
	}putchar('\n');
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}