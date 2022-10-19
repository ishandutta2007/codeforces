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
typedef long long ll;
namespace Bignum{
const int lim=1e9;
const int LG=9;
char s[10100];
int d[10100],m;
void getarr(){
	scanf("%s",s);
	int S=strlen(s);
	reverse(s,s+S);
	for(int i=0;i<S;i++)s[i]-='0';
	for(int i=0;i<S;i+=LG,m++)for(int j=i+LG-1;j>=i;j--)d[m]=10*d[m]+s[j];
	// for(int i=m-1;i>=0;i--)printf("%09d",d[i]);puts("");
}
int divide(int a){
	ll rem=0;
	for(int i=m-1;i>=0;i--)rem=lim*rem+d[i],d[i]=rem/a,rem%=a;
	while(m&&!d[m-1])m--;
	// printf("%d|",a);for(int i=m-1;i>=0;i--)printf("%09d",d[i]);printf(":%d\n",rem);
	return rem;
}
int get(int a){
	ll val=0;
	for(int i=m-1;i>=0;i--){
		val=lim*val+d[i];
		if(val>a)return -1;
	}
	return val;
}
}
int n,a[300100],b[300100],c[300100],f[300100],g[300100];
double sz[300100];int lim[300100];
int main(){
	scanf("%d",&n);
	a[1]=1;for(int i=2;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),sz[i]=sz[i-1]/a[i]+b[i],lim[i]=sz[i]+1;
	Bignum::getarr();
	for(int i=1;i<=n;i++)if(a[i]==1)c[i]=0;else c[i]=Bignum::divide(a[i]);
	// for(int i=1;i<=n;i++)printf("%d ",c[i]);puts("");
	// for(int i=1;i<=n;i++)printf("%d ",lim[i]);puts("");
	int tmp=Bignum::get(lim[n]);
	if(tmp==-1){puts("0");return 0;}
	f[tmp]=1;
	for(int i=n;i;i--){
		for(int j=lim[i];j;j--)(f[j-1]+=f[j])%=mod;
		for(int j=0;j+b[i]+1<=lim[i];j++)(f[j]+=mod-f[j+b[i]+1])%=mod;
		for(int j=0;j<=lim[i]&&1ll*j*a[i]+c[i]<=lim[i-1];j++)g[j*a[i]+c[i]]=f[j];
		for(int j=0;j<=lim[i-1];j++)f[j]=g[j],g[j]=0;
		// for(int j=0;j<=lim[i-1];j++)if(f[j])printf("[%d,%d]",j,f[j]);puts("");
	}
	printf("%d\n",f[0]);
	return 0;
}