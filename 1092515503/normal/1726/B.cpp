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
void mina(){
	scanf("%d%d",&n,&m);
	if(n>m){puts("No");return;}
	if(n&1){
		puts("Yes");
		printf("%d ",m-n+1);
		for(int i=2;i<=n;i++)printf("%d ",1);puts("");
		return;
	}
	if(m&1){puts("No");return;}
	puts("Yes");
	printf("%d %d ",(m-n+3)>>1,(m-n+3)>>1);
	for(int i=3;i<=n;i++)printf("%d ",1);puts("");
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}