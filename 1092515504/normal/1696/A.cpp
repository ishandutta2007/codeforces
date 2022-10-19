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
int T,n,m,a[2010],mx;
void mina(){
	scanf("%d%d",&n,&m),mx=-1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]|m);
	printf("%d\n",mx);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}