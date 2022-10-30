#include<bits/stdc++.h>
using namespace std;
int n,k,a[50005][15],i,j;
struct str{
	int mx[15],mn[15],num;
	bool operator <(const str &x)const
	{
		return x.mx[1]<mx[1];
	}
}tmp;
set<str> s;
int main()
{
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
		for(j=1;j<=k;++j)
			scanf("%d",&a[i][j]);
	puts("1");
	for(j=1;j<=k;++j)
		tmp.mx[j]=tmp.mn[j]=a[1][j];
	tmp.num=1;
	s.insert(tmp);
	for(i=2;i<=n;++i)
	{
		for(j=1;j<=k;++j)
			tmp.mx[j]=tmp.mn[j]=a[i][j];
		tmp.num=1;
		auto l=s.lower_bound(tmp);
		auto r=l;
		while(r!=s.end())
		{
			for(j=1;j<=k;++j)
				if(tmp.mx[j]<r->mx[j])
					break;
			if(j>k)
				break;
			++r;
		}
		while(l!=s.begin())
		{
			--l;
			for(j=1;j<=k;++j)
				if(tmp.mx[j]>l->mn[j])
					break;
			if(j>k)
			{
				++l;
				break;
			}
		}
		while(l!=r)
		{
			for(j=1;j<=k;++j)
			{
				tmp.mx[j]=max(tmp.mx[j],l->mx[j]);
				tmp.mn[j]=min(tmp.mn[j],l->mn[j]);
			}
			tmp.num+=l->num;
			auto it=l;
			++l;
			s.erase(it);
		}
		s.insert(tmp);
		printf("%d\n",s.begin()->num);
	}
}