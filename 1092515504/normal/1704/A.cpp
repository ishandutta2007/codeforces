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
int T,n,m;
char s[60],t[60];
void mina(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=0;i+1<m;i++)if(s[n-i]!=t[m-i]){puts("No");return;}
	if(find(s+1,s+(n-m+1)+1,t[1])==s+(n-m+1)+1){puts("No");return;}
	puts("Yes");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}