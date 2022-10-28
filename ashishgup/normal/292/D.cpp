#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=505;
const int M=10005;

int n, m, l, r;

typedef struct data
{
	int connected;
	int root[N], sz[N];

	void init()
	{
		for(int i=1;i<=n;i++)
		{
			root[i]=i;
			sz[i]=1;
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
		int rt1=rt(u), rt2=rt(v);

		if(rt1==rt2)
			return;

		connected--;

		if(sz[rt2]>=sz[rt1])
			swap(rt2, rt1);

		sz[rt1]+=sz[rt2];
		sz[rt2]=0;
		root[rt2]=root[rt1];

	}
}DSU;

int a[M], b[M];
DSU pref[M], suf[M];

int32_t main()
{ 
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	pref[0].init();
	for(int i=1;i<=m;i++)
	{
		pref[i]=pref[i-1];
		pref[i].merge(a[i], b[i]);
	}
	suf[m+1].init();
	for(int i=m;i>=1;i--)
	{
		suf[i]=suf[i+1];
		suf[i].merge(a[i], b[i]);
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		l--;
		r++;
		DSU current=pref[l];
		for(int j=1;j<=n;j++)
		{
			current.merge(j, suf[r].rt(j));
		}
		cout<<current.connected<<endl;
	}
	return 0;
}