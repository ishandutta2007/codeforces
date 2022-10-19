#include<bits/stdc++.h>
using namespace std;
int n,x;
int d[100005];
vector<pair<int,int> > q;
int main()
{
	scanf("%d",&n);
	cout<<"? 1"<<endl;
	for (int i=1;i<=n;++i)
		scanf("%d",&d[i]);
	int p0=0,p1=0;
	for (int i=2;i<=n;++i)
	{
		if (d[i]%2==0)
			++p0;
		else
			++p1;
		if (d[i]==1)
			q.push_back(make_pair(1,i));
	}
	int p=0;
	if (p0>p1)
		p=1;
	for (int i=2;i<=n;++i)
		if (d[i]%2==p)
		{
			cout<<"? "<<i<<endl;
			for (int j=1;j<=n;++j)
			{
				scanf("%d",&x);
				if (x==1)
					q.push_back(make_pair(min(i,j),max(i,j)));
			}
		}
	sort(q.begin(),q.end());
	puts("!");
	for (int i=0;i<(int)q.size();++i)
		if (i==0||q[i]!=q[i-1])
			cout<<q[i].first<<' '<<q[i].second<<endl;
	return 0;
}