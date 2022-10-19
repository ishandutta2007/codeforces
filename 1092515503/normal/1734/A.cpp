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
int n,a[310],res;
void mina(){
	scanf("%d",&n),res=0x7f7f7f7f;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++)res=min(res,a[i+1]-a[i-1]);
	printf("%d\n",res);
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}