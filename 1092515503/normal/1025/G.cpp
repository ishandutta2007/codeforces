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
int n,f[510],a[510],bin[510],res;
int main(){
	scanf("%d",&n);
	bin[0]=1;for(int i=1;i<=n;i++)bin[i]=(bin[i-1]<<1)%mod;
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]!=-1)f[a[i]]++;}
	for(int i=1;i<=n;i++)if(a[i]==-1)(res+=1+mod-bin[f[i]])%=mod;
	(res+=bin[n-1]-1)%=mod;
	printf("%d\n",res);
	return 0;
}