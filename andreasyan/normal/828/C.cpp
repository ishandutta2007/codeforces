#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct ban
{
	int i;
	int sl;
};
bool operator<(const ban& a,const ban& b)
{
	return a.sl>b.sl;
}
struct ban1
{
	string s;
	vector<int> a;
};

const int N=3000000;
char a[N];
int b[N];
int n,m,sl;
int ansn;
ban1 info[N];
ban infoplus[N];
int main()
{
	int i,j,k,x,l,r;
	scanf("%d",&m);
	for(k=0;k<m;++k)
	{
		cin>>info[k].s;
		infoplus[k].i=k;
		infoplus[k].sl=info[k].s.size();
		scanf("%d",&n);
		for(j=0;j<n;++j)
		{
			scanf("%d",&x);
			--x;
			info[k].a.push_back(x);
		}
	}
	////////////
	sort(infoplus,infoplus+m);
	for(k=0;k<m;++k)
	{
		sl=infoplus[k].sl;
		n=info[infoplus[k].i].a.size();
		for(j=n-1;j>=0;--j)
		{
			x=info[infoplus[k].i].a[j];
			l=x;
			r=x+sl;
			ansn=max(ansn,r);
			for(i=l;i<r;++i)
			{
				if(b[i])
				{
					i=b[i]-1;
					b[i]=max(b[i],r);
				}
				else
				{
					b[i]=r;
					a[i]=info[infoplus[k].i].s[i-l];
				}
			}
		}
	}
	for(i=0;i<ansn;++i)
	{
		if(a[i]==0)
			a[i]='a';
	}
	printf("%s\n",a);
//	system("pause");
	return 0;
}