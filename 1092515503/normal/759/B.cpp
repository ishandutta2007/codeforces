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
int n,a[100100],f[100100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,j=0,k=0;i<=n;i++){
		f[i]=f[i-1]+20;
		while(a[j+1]+90<=a[i])j++;
		while(a[k+1]+1440<=a[i])k++;
		f[i]=min(f[i],f[j]+50);
		f[i]=min(f[i],f[k]+120);
	}
	for(int i=1;i<=n;i++)printf("%d ",f[i]-f[i-1]);puts("");
	return 0;
}