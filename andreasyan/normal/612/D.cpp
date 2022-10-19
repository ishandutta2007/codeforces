#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct ban
{
	int x,y;
};
bool operator<(const ban& a,const ban& b)
{
	if(a.y<b.y)
		return true;
	if(a.y>b.y)
		return false;
	return a.x<b.x;
}
const int N=1000006,INF=999999999;

int n,m,k;
ban a[N*2];
ban t;
vector<ban> ans;
int main()
{
	int i,j,x,y,aj;
	cin>>n>>k;
	j=0;
	for(i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		t.y=x;
		t.x=1;
		a[j]=t;
		++j;
		t.y=y+1;
		t.x=-1;
		a[j]=t;
		++j;
	}
	n=j;
	sort(a,a+n);
	j=0;
	x=INF;
	for(i=0;i<n;++i)
	{
		aj=j;
		if(a[i].x==1)
			++j;
		else
			--j;
		if(aj==k-1 && j==k)
		{
			x=a[i].y;
		}
		if(aj==k && j==k-1)
		{
			t.x=x;
			t.y=a[i].y-1;
			ans.push_back(t);
		}
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();++i)
	{
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
	return 0;
}