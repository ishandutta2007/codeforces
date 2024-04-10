#include<bits/stdc++.h>
using namespace std;
int n,p,t1,t2;
double pb[100001],ans;
int main(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++)scanf("%d%d",&t1,&t2),pb[i]+=((double(t2/p-t1/p+!(t1%p)))/(t2-t1+1));
	for(int i=0;i<n;i++)ans+=1.0-(1.0-pb[i])*(1.0-pb[(i+1)%n]);
	printf("%lf\n",ans*2000);
	return 0;
}