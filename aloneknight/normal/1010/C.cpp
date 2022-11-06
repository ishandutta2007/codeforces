#include<bits/stdc++.h>
using namespace std;
int n,k,gg,a,cnt,d[100005];
int main()
{
	scanf("%d%d",&n,&k);gg=k;
	for(int i=1;i<=n;i++)scanf("%d",&a),gg=__gcd(gg,a);
	cnt=1;d[0]=1;
	if(!d[gg%k])d[gg%k]=1,cnt++;
	for(int i=gg*2;i%k!=gg%k;i+=gg)if(!d[i%k])d[i%k]=1,cnt++;
	printf("%d\n",cnt);
	for(int i=0;i<k;i++)if(d[i])printf("%d ",i);
	return 0;
}