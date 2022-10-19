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
int n,a[100100],b[100100];
vector<int>u,v;
void mina(){
	scanf("%d",&n),res=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),res+=b[i];
	for(int i=1;i<=n;i++)if(a[i]==0)u.push_back(b[i]);else v.push_back(b[i]);
	sort(u.begin(),u.end()),sort(v.begin(),v.end());
	if(u.size()<v.size())swap(u,v);
	res<<=1;
	if(u.size()==v.size())res-=min(u[0],v[0]);
	else{
		for(int i=0;i<u.size()-v.size();i++)res-=u[i];
	}
	u.clear(),v.clear();
	printf("%lld\n",res);
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}