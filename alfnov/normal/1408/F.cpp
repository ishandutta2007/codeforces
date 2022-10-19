#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int l,r;
	apple(int l=0,int r=0):l(l),r(r){}
}ans[1000005];
int n,tot=0,lg[1000005];
void gds(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	gds(l,mid);
	gds(mid+1,r);
	for(int i=l;i<=mid;i++)ans[++tot]=apple(i,i-l+mid+1);
}
int main()
{
	lg[1]=1;
	for(int i=2;i<=1000000;i++)lg[i]=lg[i>>1]<<1;
	int n;
	cin>>n;
	gds(1,lg[n]);
	gds(n-lg[n]+1,n);
	cout<<tot<<endl;
	for(int i=1;i<=tot;i++)printf("%d %d\n",ans[i].l,ans[i].r);
	return 0;
}