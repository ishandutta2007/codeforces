#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N];
int connected;
int root[N], sz[N], val[N];

void init()
{
	for(int i=0;i<=256;i++)
	{
		root[i]=i;
		sz[i]=1;
		val[i]=i;
	}
	connected=n;
}

int rt(int k)
{
	while(k!=root[k])
	{
		root[k]=root[root[k]];
		k=root[k];
	}
	return k;
}

void merge(int u, int v)
{
	int rt1=rt(u);
	int rt2=rt(v);

	if(rt1==rt2)
		return;

	connected--;

	if(sz[rt2]>=sz[rt1])
	{
		sz[rt2]+=sz[rt1];
		sz[rt1]=0;
		root[rt1]=root[rt2];
		val[rt2]=min(val[rt1], val[rt2]);
	}
	else
	{
		sz[rt1]+=sz[rt2];
		sz[rt2]=0;
		root[rt2]=root[rt1];
		val[rt1]=min(val[rt1], val[rt2]);
	}
}

int assign(int cur)
{
	int last=cur-1;
	while(last>=0 && sz[rt(last)] + sz[rt(cur)] <=k)
	{
		merge(cur, last);
		last--;
	}
	return val[rt(cur)];
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=assign(a[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}