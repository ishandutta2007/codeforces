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
int n,m,s[100100],a[100100];
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=n-m+1;i<=n;i++)scanf("%d",&s[i]),a[i]=s[i]-s[i-1];
	if(m==1){puts("YES");return;}
	for(int i=n-m+2;i<n;i++)if(a[i]>a[i+1]){puts("NO");return;}
	long long sum=0;
	for(int i=n-m+1;i;i--)sum+=a[n-m+2];
	puts(sum>=s[n-m+1]?"YES":"NO");
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}