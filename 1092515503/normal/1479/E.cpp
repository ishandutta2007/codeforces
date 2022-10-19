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
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int m,n,a[1010],res;
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),n+=a[i];
	sort(a+1,a+m+1);
	int p=1;
	int P1=0,Q1=1,P2=mod-2,Q2=1;
	while(p<=m&&a[p]==1)(res+=mod-2)%=mod,p++;
	for(int i=1;i<n;i++){
		int P3=(1ll*(3*n-2*i)*P2%mod*Q1+mod-1ll*(2*n-i)*P1%mod*Q2%mod)%mod;
		int Q3=1ll*Q1*Q2%mod*(n-i)%mod;
		while(p<=m&&a[p]==i+1)(res+=1ll*P3*ksm(Q3)%mod)%=mod,p++;
		P1=P2,Q1=Q2;
		P2=P3,Q2=Q3;
	}
	(res+=mod-1ll*P2*ksm(Q2)%mod)%=mod;
	printf("%d\n",res);
	return 0;
}