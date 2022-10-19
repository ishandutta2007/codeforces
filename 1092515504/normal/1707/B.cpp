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
int T,n,a[100100];
void fullfunc(){
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];
	n--;
	sort(a+1,a+n+1);
}
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	// for(int _=1;n>1&&_<=80;_++)fullfunc();
	int zer=0;while(zer<n&&!a[zer+1])zer++;
	while(n>1){
		for(int i=max(zer,1);i<n;i++)a[i]=a[i+1]-a[i];
		n--;
		sort(a+max(zer,1),a+n+1);
		if(zer)zer--;
		while(zer<n&&!a[zer+1])zer++;
	}
	printf("%d\n",a[n]);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}