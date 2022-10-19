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
int T,n,m,a[200100];
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int i=1,mn=0x3f3f3f3f,mx=0,res=0;
	for(;i<=n;i++){
		mn=min(mn,a[i]),mx=max(mx,a[i]);
		if(mx-mn>(m<<1))
			mn=mx=a[i],res++;
	}
	printf("%d\n",res);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
12 8
25 3 3 17 8 6 1 16 15 25 17 23
*/