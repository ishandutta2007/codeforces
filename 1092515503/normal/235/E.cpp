/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
int a,b,c,n,pri[4001000],mu[4001000];
void sieve(){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!pri[i])pri[++pri[0]]=i,mu[i]=-1;
		for(int j=1;j<=pri[0]&&i*pri[j]<=n;j++){
			pri[i*pri[j]]=true;
			if(!(i%pri[j]))break;
			mu[i*pri[j]]=-mu[i]; 
		}
	}
}
ui f[4001000],res;
int main(){
    scanf("%d%d%d",&a,&b,&c),n=a*b,sieve();
    for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)if(__gcd(i,j)==1)f[i*j]+=(a/i)*(b/j);
    for(int i=1;i<=pri[0];i++)for(int j=n/pri[i];j;j--)f[j]+=f[j*pri[i]];
    for(int i=1;i<=c;i++)for(int j=i;j<=c;j+=i)res+=mu[i]*f[i]*(c/j);
    printf("%u\n",res&((1<<30)-1));
    return 0;
}