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
int T,n,a[100100],res;
void mina(){
	scanf("%d",&n),res=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int l=1,r;l<=n;l=r){
		while(l<=n&&!a[l])l++;
		if(l>n)break;
		for(r=l;r<=n&&a[r];r++);
		res++;
	}
	printf("%d\n",min(res,2));
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}