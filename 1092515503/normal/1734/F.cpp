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
ll n,m;
ll f[62][2][2][2];
ll DP(int pos,bool par,bool car,bool lim){
	if(pos==-1)return par&&!car;
	ll&res=f[pos][par][car][lim];if(res!=-1)return res;res=0;
	for(int i=0;i<=(lim?(m>>pos)&1:1);i++)for(int j=0;j<2;j++)
		if(((((n>>pos)&1)+i+j)>=2)==car)
			res+=DP(pos-1,par^((n>>pos)&1)^j,j,lim&&(i==((m>>pos)&1)));
	return res;
}
int T;
void mina(){
	scanf("%lld%lld",&n,&m),m--;
	memset(f,-1,sizeof(f));
	printf("%lld\n",DP(61,false,false,true));
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}