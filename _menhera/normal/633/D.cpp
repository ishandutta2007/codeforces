#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int MAXN = 1010;
int N;
long long a[MAXN];
long long cp[MAXN];
multiset<long long> pshed;
multiset<long long> poped;
set<pair<long long, long long> > t;
int main()
{
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%lld",a+i);
		cp[i] = a[i];
		pshed.insert(a[i]);
	}
	int maxv = 2;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i==j) continue;
			if(t.find(make_pair(a[i],a[j]))!=t.end())
				continue;
			t.insert(make_pair(a[i],a[j]));
			pshed.erase(pshed.find(a[i]));
			pshed.erase(pshed.find(a[j]));
			long long xx = a[i];
			long long yy = a[j];
			poped.insert(xx);
			poped.insert(yy);
			while(true)
			{
				xx^=yy^=xx^=yy;
				xx+=yy;
				if(pshed.find(xx)==pshed.end())
					break;
				pshed.erase(pshed.find(xx));
				poped.insert(xx);
			}
			maxv=max(maxv, (int)poped.size());
			for(auto i: poped)
				pshed.insert(i);
			poped.clear();
		}
	}
	printf("%d",maxv);
}