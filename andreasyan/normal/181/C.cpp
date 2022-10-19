#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct ban
{
	int a,b,c;
};
struct ban1
{
	int x,d;
};
bool operator<(const ban1& a,const ban1& b)
{
	return a.d>b.d;
}

int n,m,k;
string s;
ban a[12][102];
ban1 b[102];
int ans;
int main()
{
	int i,j,ii,jj;
	cin>>n>>m>>k;
	int ck=k;
	for(i=0;i<n;++i)
	{
		cin>>s;
		for(j=0;j<m;++j)
		{
			cin>>a[i][j].a>>a[i][j].b>>a[i][j].c;
		}
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(j==i)
				continue;
			k=ck;
			int yans=0;
			for(ii=0;ii<m;++ii)
			{
				b[ii].x=ii;
				b[ii].d=-a[i][ii].a+a[j][ii].b;
			}
			sort(b,b+m);
			for(ii=0;ii<m;++ii)
			{
				if(b[ii].d<=0)
					break;
				int inchqan=a[i][b[ii].x].c;
				if(k>=inchqan)
				{
					k-=inchqan;
					yans+=inchqan*b[ii].d;
				}
				else
				{
					inchqan=k;
					yans+=inchqan*b[ii].d;
					break;
				}
			}
			ans=max(ans,yans);
		}
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}