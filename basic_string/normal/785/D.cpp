#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=1e9+7;
char s[N];
int fc[N],ifc[N],sf[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int C(int n,int m){return fc[n]*1ll*ifc[m]%P*ifc[n-m]%P;}
int main(){
	int i,n,pr=0,w=0;
	scanf("%s",s+1),n=strlen(s+1),fc[0]=1;
	for(i=1;i<=n;++i)fc[i]=fc[i-1]*1ll*i%P;
	for(ifc[n]=qp(fc[n],P-2),i=n;i;--i)ifc[i-1]=ifc[i]*1ll*i%P;
	for(i=n;i;--i)sf[i]=sf[i+1]+(s[i]==')');
	for(i=1;i<=n;++i)if(s[i]=='(')if(++pr,sf[i])w=(w+C(pr-1+sf[i],sf[i]-1))%P;
	printf("%d",w);
	return 0;
}