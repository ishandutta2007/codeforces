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
int n,a[100100],res,fac[100100],inv[100100];
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
void mina(){
	scanf("%d",&n),res=1;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	long long sl=0,sr=0;
	for(int i=1,j=n;;){
		int X=(i!=1),Y=(j!=n),num=0;
		while(i<=j&&!a[i])i++,X++;
		while(i<=j&&!a[j])j--,Y++;
		if(i>j){
			for(int k=1;k<X+Y;k++)(res<<=1)%=mod;
			break;
		}
		for(int k=0;k<=min(X,Y);k++)(num+=1ll*C(X,k)*C(Y,k)%mod)%=mod;
		res=1ll*res*num%mod;
		if(i==j)break;
		sl+=a[i++],sr+=a[j--];
		while(sl!=sr&&i<=j){
			if(sl<sr)sl+=a[i++];
			else sr+=a[j--];
		}
		if(sl!=sr)break;
	}
	printf("%d\n",res);
}
int T;
int main(){
	// freopen("E.in","r",stdin);
	// freopen("E.out","w",stdout);
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
4
1 2 0 2 
3
2 0 1 
9
1 0 2 2 2 0 2 2 2 
6
0 0 1 2 2 0 
*/