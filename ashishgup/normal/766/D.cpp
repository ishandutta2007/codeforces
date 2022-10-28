#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, q, col=0;
int color[N], root[N], sz[N];
string a[N];
map<int, int> c;
map<string, int> convert;

void init()
{
	for(int i=1;i<=n;i++)
	{
		root[i]=i;
		sz[i]=1;
		root[i+n]=i+n;
		sz[i+n]=1;
	}
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

	if(sz[rt2]>=sz[rt1])
	{
		sz[rt2]+=sz[rt1];
		sz[rt1]=0;
		root[rt1]=root[rt2];
	}

	else
	{
		sz[rt1]+=sz[rt2];
		sz[rt2]=0;
		root[rt2]=root[rt1];
	}
}

int32_t main()
{
	IOS;
	memset(color, -1, sizeof(color));
	cin>>n>>m>>q;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		convert[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		bool check=1;
		int type;
		cin>>type;
		string x, y;
		cin>>x>>y;
		int u, v;
		u=convert[x];
		v=convert[y];
		if(type==1)
		{
			if(rt(u)==rt(v+n))
				check=0;
			else
			{
				merge(u, v);
				merge(u+n, v+n);
			}
		}
		else
		{
			if(rt(u)==rt(v))
				check=0;
			else
			{
				merge(u, v+n);
				merge(v, u+n);
			}
		}
		if(!check)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		string x, y;
		cin>>x>>y;
		int u, v;
		u=convert[x];
		v=convert[y];
		if(rt(u)==rt(v))
			cout<<"1"<<endl;
		else if(rt(u)==rt(v+n))
			cout<<"2"<<endl;
		else
			cout<<"3"<<endl;
	}
	return 0;
}