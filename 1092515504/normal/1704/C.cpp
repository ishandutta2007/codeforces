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
int T,n,m,a[100100],res;
vector<int>v;
void mina(){
	scanf("%d%d",&n,&m),res=0;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	for(int i=1;i<m;i++)if(a[i+1]-a[i]>1)v.push_back(a[i+1]-a[i]-1);
	if(a[m]!=n||a[1]!=1)v.push_back(n-a[m]+a[1]-1);
	sort(v.rbegin(),v.rend());
	// for(auto x:v)printf("%d ",x);puts("");
	for(int i=0;i<v.size();i++){
		v[i]-=i<<2;
		if(v[i]>0)res++/*,printf("%d:A\n",i)*/;
		v[i]-=2;
		if(v[i]>0)res+=v[i]/*,printf("%d:B:%d\n",i,v[i])*/;
	}
	printf("%d\n",n-res);
	v.clear();
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