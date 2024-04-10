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
const int mod=1e9+7;
int n,m,len[1001000],f[1001000],sum[2][1001000],stk[1001000],tp;
char s[1001000];
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	if(s[1]!='0')len[++m]=0;
	for(int l=1,r=1;l<=n;l=r){
		while(r<=n&&s[r]==s[l])r++;
		len[++m]=r-l;
	}
	if(m==1){printf("%d\n",n);return 0;}
	if(s[n]=='0')m--;
	for(int i=1;i<=m;i++){
		sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1];
		if(!(i&1)){
			f[i]=1ll*(sum[0][i-1]+len[1]+1)*len[i]%mod;
			(sum[1][i]+=f[i])%=mod;
		}else{
			f[i]=1ll*len[i]*f[i-1]%mod;
			while(tp&&len[stk[tp]]<len[i])
				f[i]=(1ll*(len[i]-len[stk[tp]])*(sum[1][stk[tp]]+mod-sum[1][stk[tp-1]])+f[i])%mod,tp--;
			stk[++tp]=i;
			(sum[0][i]+=f[i])%=mod;
		}
		// printf("%d,%d:%d\n",i,len[i],f[i]);
	}
	printf("%d\n",1ll*sum[1][m]*(len[m+1]+1)%mod);
	return 0;
}