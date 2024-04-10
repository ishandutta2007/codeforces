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
int n;
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=i;j++)printf("%d ",j==1||j==i);
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}