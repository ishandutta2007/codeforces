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
int n,a[100100];
long long mxv,tag;
int d[100100],p[100100],q[100100];
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),d[i]=0,p[i]=i;
	mxv=tag=0;
	for(int i=1;i<=n;i++){
		if(mxv>a[i]+tag)d[i]=mxv-(a[i]+tag),tag+=d[i];
		mxv=max(mxv,a[i]+tag);
	}
	sort(p+1,p+n+1,[](const int&u,const int&v){return d[u]<d[v];});
	for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}
/*
10
7
7 1 6 2 5 3 4
*/