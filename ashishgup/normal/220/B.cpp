#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

struct data
{
	int l, r, ind;	
};

int n, m;
int a[N], bit[N], ans[N];
vector<int> v[N];
data queries[N];

bool comp(data &d1, data &d2)
{
	if(d1.r<d2.r)
		return true;
	if(d1.r>d2.r)
		return false;
	return d1.l<d2.l;
}

void update(int i, int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=(i&(-i));
	}
}

int pref(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=bit[i];
		i-=(i&(-i));
	}
	return ans;
}

int rsum(int L, int R)
{
	return pref(R) - pref(L-1);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1e5)
			a[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>queries[i].l>>queries[i].r;
		queries[i].ind=i;
	}
	sort(queries+1, queries+m+1, comp);
	int ind=1;
	for(int R=1;R<=n;R++)
	{
		int x=a[R];
		if(x)
		{
			v[x].push_back(R);
			int sz=v[x].size();
			if(sz>=x)
			{
				update(v[x][sz-x], +1);
			}
			if(sz>=x+1)
			{
				update(v[x][sz-x-1], -2);
			}
			if(sz>=x+2)
			{
				update(v[x][sz-x-2], +1);
			}
		}
		while(ind<=m && queries[ind].r==R)
		{
			ans[queries[ind].ind]=rsum(queries[ind].l, queries[ind].r);
			ind++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
}