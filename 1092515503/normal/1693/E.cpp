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
int n,a[200100];
int bit[200100];
void ADD(int x){while(x<=n)bit[x]++,x+=x&-x;}
int SUM(int x){int ret=0;while(x)ret+=bit[x],x-=x&-x;return ret;}
vector<int>v[200100];
ll res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[a[i]].push_back(i);
	for(int i=n,l=1,r=n;i;i--)if(!v[i].empty()){//l is the first place of uncertain, while r is the last.
		int L=v[i][0],R=v[i].back();
		res+=v[i].size();
		res+=SUM(R)-SUM(L);
		if(r<L)res+=SUM(L)-SUM(r),l=r+1,r=R;
		else if(R<l)res+=SUM(l-1)-SUM(R),r=l-1,l=L;
		else l=L,r=R;
		for(auto x:v[i])ADD(x);
		// printf("%d:[%d,%d]:%lld\n",i,l,r,res);
	}
	printf("%lld\n",res);
	return 0;
}