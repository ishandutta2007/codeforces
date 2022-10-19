#include <iostream>
using namespace std;

const int N=100005;
int n,m,k,a[N],b[N],ans;
int c[N];
int t;
bool st(int x)
{
	int i,j,z;
	for(i=1;i<=m;i++)
	{
		c[i]=0;
	}
	for(i=x;i>0;i--)
	{
		if(!c[a[i]] && a[i])
			c[a[i]]=i;
	}
	for(i=1;i<=m;i++)
	{
		if(!c[i])
			return false;
	}
	z=1;
	for(i=1;i<=x;i++)
	{
		if(c[a[i]]==i)
		{
			t=0;
			bool e=false;
			for(j=z;j<i;j++)
			{
				if(t==b[a[i]])
				{
					z=j;
					e=true;
					break;
				}
				if(c[a[j]]!=j || !a[j])
				{
					t++;
				}
			}
			if(t==b[a[i]])
			{
				z=j;
				e=true;
			}
			if(!e)
				return false;
		}
	}
	ans=x;
	return true;
}
void erksr()
{
	int i,j,l=1,r=n,me;
	while(1)
	{
		me=(r+l)/2;
		if(st(me))
		{
			if(l>=r)
				break;
			r=me-1;
		}
		else
		{
			if(l>=r)
				break;
			l=me+1;
		}
	}
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>b[i];
	erksr();
	if(ans==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}