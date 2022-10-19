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
int T,n,m,res;
ll c[300100],s[100100];
void mina(){
	scanf("%d%d",&n,&m);
	for(int _=1;_<=n;_++){
		for(int i=1;i<=m;i++)scanf("%lld",&c[i]),c[i]+=c[i-1];
		s[_]=0;
		for(int i=1;i<=m;i++)s[_]+=c[i];
	}
	printf("%d %lld\n",min_element(s+1,s+n+1)-s,*max_element(s+1,s+n+1)-*min_element(s+1,s+n+1));
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
12 8
25 3 3 17 8 6 1 16 15 25 17 23
*/