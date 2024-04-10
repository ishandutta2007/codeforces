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
int T,n,a[250100],dis[250010],stk[250010],tp,lmx[250010],lmn[250010];
int amx[250100][20],amn[250100][20];
int fmx[250100][20],fmn[250100][20];
deque<int>q;
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		while(tp&&a[stk[tp]]>a[i])tp--;
		lmn[i]=stk[tp],stk[++tp]=i;
	}tp=0;
	for(int i=1;i<=n;i++){
		while(tp&&a[stk[tp]]<a[i])tp--;
		lmx[i]=stk[tp],stk[++tp]=i;
	}tp=0;
	for(int i=2;i<=n;i++){
		amn[i][0]=lmn[i],fmn[i][0]=dis[amn[i][0]];
		for(int j=1;j<20;j++)amn[i][j]=amn[amn[i][j-1]][j-1],fmn[i][j]=min(fmn[i][j-1],fmn[amn[i][j-1]][j-1]);
		amx[i][0]=lmx[i],fmx[i][0]=dis[amx[i][0]];
		for(int j=1;j<20;j++)amx[i][j]=amx[amx[i][j-1]][j-1],fmx[i][j]=min(fmx[i][j-1],fmx[amx[i][j-1]][j-1]);

		dis[i]=0x3f3f3f3f;
		for(int j=19,x=i;j>=0;j--)if(amn[x][j]>lmx[i])dis[i]=min(dis[i],fmn[x][j]),x=amn[x][j];
		for(int j=19,x=i;j>=0;j--)if(amx[x][j]>lmn[i])dis[i]=min(dis[i],fmx[x][j]),x=amx[x][j];
		dis[i]++;
	}
	printf("%d\n",dis[n]);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}