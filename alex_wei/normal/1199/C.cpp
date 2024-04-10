#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,num;
}a[400002];
bool cmp(node a,node b){return a.val<b.val;}
int n,l,b[400002],cnt,lef=1,rit=1,sum,ans=1e6;
int main()
{
	cin>>n>>l,l=(l*8)/n;
	for(int i=1;i<=n;i++)cin>>a[i].val,a[i].num=i;
	sort(a+1,a+n+1,cmp);
	a[0].val=-1;
	for(int i=1;i<=n;i++)
		if(a[i].val!=a[i-1].val)
			cnt++,b[cnt]++;
		else b[cnt]++;
	sum=b[1];
	while(lef<=cnt){
		if(lef!=rit&&(int)log2(rit-lef)+1>l)
			sum-=b[lef++];
		else{
			ans=min(ans,n-sum);
			if(rit==cnt)sum-=b[lef++];
			else sum+=b[++rit];
		}
	}
	cout<<ans;
	return 0;
}