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
typedef long long ll;
ll f[210],s[210],sum;int lim;
int n,a[210],m;
void mina(){
	scanf("%d",&n),sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	m=lower_bound(s,s+lim+1,sum)-s;
	if(s[m]!=sum){puts("NO");return;}
	for(int i=m,las=-1,j,k;i>=0;i--){
		for(j=1,k=0;j<=n;j++)if(j!=las&&a[j]>a[k])k=j;
		if(a[k]<f[i]){puts("NO");return;}
		a[k]-=f[i],las=k;
	}
	puts("YES");
}
int T;
int main(){
	f[0]=s[0]=f[lim=1]=1;
	while(f[lim-1]+f[lim]<=1e14)lim++,f[lim]=f[lim-1]+f[lim-2];
	for(int i=1;i<=lim;i++)s[i]=s[i-1]+f[i];
	// for(int i=0;i<=lim;i++)printf("%lld ",f[i]);puts("");
	scanf("%d",&T);while(T--)mina();return 0;
}