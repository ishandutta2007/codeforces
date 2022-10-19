#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=200005;
struct ban
{
	int x,l,r;
};

int n,q,m;
int a[N];
ban b[N];
int main()
{
	cin>>n>>q>>m;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i<q;++i)
		scanf("%d%d%d",&b[i].x,&b[i].l,&b[i].r);
	for(int k=0;k<m;++k)
	{
		int i;
		scanf("%d",&i);
		for(int j=q-1;j>=0;--j)
		{
			int x=b[j].x;
			int l=b[j].l;
			int r=b[j].r;
			if(i>=l && i<=r)
			{
				if(x==1)
				{
					if(i==l)
						i=r;
					else
						--i;
				}
				else
				{
					i=(r-(i-l));
				}
			}
		}
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}