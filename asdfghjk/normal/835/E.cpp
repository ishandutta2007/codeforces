#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int l,r;
};
vector<node> vct;
int n,x,y,p[1005],ans[20],cnt;
void phh(int l,int r)
{
	if(l==r)
	{
		ans[++cnt]=l;
		return;
	}
	int i,mid=(l+r)/2,len=0;
	for(i=l;i<=mid;++i)
		p[++len]=i;
	cout<<'?'<<' '<<len;
	for(i=1;i<=len;++i)
		cout<<' '<<p[i];
	cout<<endl;
	cout.flush();
	cin>>i;
	if((i^(len&1?x:0))==0)
		phh(mid+1,r);
	else
		phh(l,mid);
}
void dzx()
{
	int i,j,lt,rt,mid,len;
	lt=0,rt=vct.size()-1;
	while(lt<rt)
	{
		mid=lt+rt>>1;
		len=0;
		for(i=0;i<=mid;++i)
			for(j=vct[i].l;j<=(vct[i].l+vct[i].r)/2;++j)
				p[++len]=j;
		cout<<'?'<<' '<<len;
		for(i=1;i<=len;++i)
			cout<<' '<<p[i];
		cout<<endl;
		cout.flush();
		cin>>i;
		if((i^(len&1?x:0))==0)
			lt=mid+1;
		else
			rt=mid;
	}
	i=(vct[lt].l+vct[lt].r)/2;
	phh(vct[lt].l,i);
	phh(i+1,vct[lt].r);
}
void work()
{
	int i,j,len=0;
	for(i=vct.size()-1;i>=0;--i)
		for(j=vct[i].l;j<=(vct[i].l+vct[i].r)/2;++j)
			p[++len]=j;
	cout<<'?'<<' '<<len;
	for(i=1;i<=len;++i)
		cout<<' '<<p[i];
	cout<<endl;
	cout.flush();
	cin>>i;
	if((i^(len&1?x:0))==0)
	{
		for(i=vct.size()-1;i>=0;--i)
		if(vct[i].l!=vct[i].r)
		{
			j=(vct[i].l+vct[i].r)/2;
			vct.push_back((node){j+1,vct[i].r});
			vct[i].r=j;
		}
		work();
	}
	else
		dzx();
}
int main()
{
	cin>>n>>x>>y;
	vct.push_back((node){1,n});
	work();
	cout<<'!'<<' '<<ans[1]<<' '<<ans[2];
	return 0;
}