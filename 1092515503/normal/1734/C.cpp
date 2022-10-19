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
long long res;
int n;
char s[1001000];
bool era[1001000];
void mina(){
	scanf("%d%s",&n,s+1),res=0;
	for(int i=1;i<=n;i++)era[i]=false;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i){
		if(s[j]=='1')break;
		if(!era[j])era[j]=true,res+=i;
	}
	printf("%lld\n",res);
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}