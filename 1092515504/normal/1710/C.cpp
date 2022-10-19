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
char s[200100];int S;
int f[200100][2][2][2][2][2][2];
//A=a^b
//B=b^c
//C=c^a
int dfs(int P,bool da,bool db,bool dc,bool la,bool lb,bool lc){
	if(P>=S)return da&&db&&dc;
	int&res=f[P][da][db][dc][la][lb][lc];
	if(res!=-1)return res;res=0;
	for(int i=0;i<=(la?s[P]:1);i++)
	for(int j=0;j<=(lb?s[P]:1);j++)
	for(int k=0;k<=(lc?s[P]:1);k++)
		(res+=dfs(P+1,da||((i^j)&&(j^k)),db||((j^k)&&(k^i)),dc||((k^i)&&(i^j)),la&&i==s[P],lb&&j==s[P],lc&&k==s[P]))%=mod;
	return res;
}
int main(){
	scanf("%s",s),S=strlen(s);
	for(int i=0;i<S;i++)s[i]-='0';
	memset(f,-1,sizeof(f));
	printf("%d\n",dfs(0,false,false,false,true,true,true));
	return 0;
}