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
int T,n,m,K,a[100100],b[100100];
bool amin(){
	long long sum=0,num=0;
	for(int i=1;i<=K;i++)b[i]=a[i]/n;
	sort(b+1,b+K+1);
	for(int i=1;i<=K;i++)if(b[i]>1)sum+=b[i],num++;
	if(sum<m)return false;
	if((num<<1)<=m)return true;
	if(b[K]<=2&&(m&1))return false;
	return true;
}
void mina(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=K;i++)scanf("%d",&a[i]);
	if(amin()){puts("Yes");return;}
	swap(n,m);
	if(amin()){puts("Yes");return;}
	puts("No");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}