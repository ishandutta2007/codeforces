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
int n,a[2010],b[2010],mx;
void mina(){
	scanf("%d",&n),mx=0xc0c0c0c0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)mx=max(mx,a[i]-a[1]);
	for(int i=1;i<n;i++)mx=max(mx,a[n]-a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=a[j];
		rotate(b+1,b+i,b+n+1);
		mx=max(mx,b[n]-b[1]);
	}
	printf("%d\n",mx);
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}