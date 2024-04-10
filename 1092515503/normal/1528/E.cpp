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
const int inv2=499122177;
const int inv6=166374059;
int n,f[1001000],g[1001000];
int main(){
	scanf("%d",&n);
	f[0]=g[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=2)f[i]=1ll*f[i-1]*g[i-2]%mod;//a son of i-1 and a son less than i-1
		(f[i]+=1ll*f[i-1]*(f[i-1]-1)%mod*inv2%mod)%=mod;//two different sons of i-1
		(f[i]+=f[i-1])%=mod;//two same sons of i-1
		(f[i]+=f[i-1])%=mod;//one son of i-1.
		g[i]=(g[i-1]+f[i])%mod;
	}
	int res1=0;if(n>=2)res1=1ll*f[n-1]*g[n-2]%mod*(g[n-2]-1)%mod*inv2%mod;//one son of n-1 and two different sons less than n-1
	int res2=0;if(n>=2)res2=1ll*f[n-1]*g[n-2]%mod;//one son of n-1 and two same sons less than n-1
	int res3=0;if(n>=2)res3=1ll*f[n-1]*g[n-2]%mod;//one son of n-1 and one son less than n-1
	int res4=0;if(n>=2)res4=1ll*f[n-1]*(f[n-1]-1)%mod*inv2%mod*g[n-2]%mod;//two different sons of n-1 and one son less than n-1
	int res5=0;if(n>=2)res5=1ll*f[n-1]*g[n-2]%mod;//two same sons of n-1 and one son less than n-1
	
	int res6=1ll*f[n-1]*(f[n-1]-1)%mod*(f[n-1]-2)%mod*inv6%mod;//three different sons of n-1
	int res7=1ll*f[n-1]*(f[n-1]-1)%mod;//two same sons of n-1 and one different son of n-1
	int res8=f[n-1];//three same sons of n-1
	int res9=1ll*f[n-1]*(f[n-1]-1)%mod*inv2%mod;//two different sons of n-1
	int res10=f[n-1];//two same sons of n-1;
	int res11=f[n-1];//one son of n-1;
	// printf("%d %d %d %d %d %d %d %d %d %d %d\n",res1,res2,res3,res4,res5,res6,res7,res8,res9,res10,res11);
	int ser1=(0ll+res1+res2+res3+res4+res5+res6+res7+res8+res9+res10+res11)%mod;
	int ser2=(2ll*ser1+mod-1)%mod;
	int ser3=0;
	for(int i=1;i+1<n;i++){
		int ans1=0;if(i>=2)ans1=1ll*f[i-1]*g[i-2]%mod;
		int ans2=1ll*f[i-1]*(f[i-1]-1)%mod*inv2%mod;
		int ans3=f[i-1];
		int sna1=(0ll+ans1+ans2+ans3)%mod;
		int sna2=(f[n-i-1]+mod-1)%mod;//substract the situation of solely a chain
		// printf("%d:%d,%d\n",i,sna1,sna2);
		ser3=(1ll*sna1*sna2+ser3)%mod;
	}
	int qwq=(ser2+ser3)%mod;
	printf("%d\n",qwq);
	return 0;
}