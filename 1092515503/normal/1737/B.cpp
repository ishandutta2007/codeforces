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
long long l,r;
ll count(ll x){
	ll y=sqrt(x);
	ll res=3*max(y-6,0ll);
	for(ll z=y+5;z>=y-5&&z>0;z--)for(ll m=z;m<=z+2;m++)if(z*m<=x)res++;
	return res;
}
void mina(){
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",count(r)-count(l-1));
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}