#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,P=998244353;
int jc[N],ijc[N],s1[N],s2[N],s3[N],s4[N];
char s[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int C(int n,int m){
	if(n<m||m<0)return 0;
	return jc[n]*1ll*ijc[m]%P*ijc[n-m]%P;
}
int main(){
	int n,i,w=0;
	scanf("%s",s+1),n=strlen(s+1),jc[0]=1;
	for(i=1;i<=n;++i)s1[i]=s1[i-1]+(s[i]=='('),s2[i]=s2[i-1]+(s[i]=='?');
	for(i=n;i;--i)s3[i-1]=s3[i]+(s[i]==')'),s4[i-1]=s4[i]+(s[i]=='?');
	for(i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%P;
	ijc[n]=qp(jc[n],P-2);
	for(i=n;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(i=1;i<n;++i)w=(w+s1[i]*1ll*C(s2[i]+s4[i],s4[i]+s3[i]-s1[i])+s2[i]*1ll*C(s2[i]+s4[i]-1,s3[i]+s4[i]-s1[i]-1))%P;
	printf("%d",w);
	return 0;
}