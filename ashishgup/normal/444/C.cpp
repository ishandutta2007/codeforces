#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;
const int SZ=320;

int n, m;
int a[N];

struct sqrtDecomposition
{
	int L, R;
	int col[SZ], contrib[SZ];
	bool lazy=0;
	int extra=0;
	int sumBlock=0;
	int lazyValue=0;

	void init(int l, int r)
	{
		for(int i=l;i<=r;i++)
		{
			col[i-l]=a[i];
			contrib[i]=0;
		}
		L=l, R=r;
		extra=0;
		sumBlock=0;
		lazyValue=0;
	}

	void semiUpdate(int l, int r, int val)
	{
		if(l>r)
			return;
		if(lazy)
		{
			for(int i=L;i<=R;i++)
			{
				contrib[i-L]+=extra;
				col[i-L]=lazyValue;
			}
			lazy=0;
			extra=0;
		}
		for(int i=l;i<=r;i++)
		{
			sumBlock+=abs(val-col[i-L]);
			contrib[i-L]+=abs(val-col[i-L]);
			col[i-L]=val;
		}
	}	

	void fullUpdate(int val)
	{
		if(lazy)
		{
			sumBlock+=(abs(val-lazyValue)*(R-L+1));
			extra+=abs(val-lazyValue);
		}
		else
		{
			for(int i=L;i<=R;i++)
			{
				contrib[i-L]+=abs(col[i-L]-val);
				sumBlock+=abs(col[i-L]-val);
				col[i-L]=val;
			}
		}
		lazy=1;
		lazyValue=val;
	}

	void update(int l, int r, int val)
	{
		if(l<=L && r>=R)
			fullUpdate(val);
		else
			semiUpdate(max(l, L), min(r, R), val);
	}

	int semiQuery(int l, int r)
	{
		if(l>r)
			return 0;
		if(lazy)
		{
			for(int i=L;i<=R;i++)
			{
				contrib[i-L]+=extra;
				col[i-L]=lazyValue;
			}
			lazy=0;
			extra=0;
		}
		int answer=0;
		for(int i=l;i<=r;i++)
			answer+=contrib[i-L];
		return answer;
	}

	int fullQuery()
	{
		return sumBlock;
	}	

	int query(int l, int r)
	{
		if(l<=L && r>=R)
			return fullQuery();
		else
			return semiQuery(max(l, L), min(r, R));
	}

};

sqrtDecomposition blcks[SZ+5];

void init()
{
	int blocks=n/SZ + 1;
	int curL=1, curR=SZ;
	for(int i=1;i<=blocks;i++)
	{
		curR=min(curR, n);
		blcks[i].init(curL, curR);
		curL+=SZ;
		curR+=SZ;
	}
}	

void update(int l, int r, int x)
{	
	int left=(l-1)/SZ  + 1;
	int right=(r-1)/SZ + 1;
	for(int i=left;i<=right;i++)
		blcks[i].update(l, r, x);		
}

int query(int l, int r)
{	
	int left=(l-1)/SZ  + 1;
	int right=(r-1)/SZ + 1;
	int answer=0;
	for(int i=left;i<=right;i++)
		answer+=blcks[i].query(l, r);
	return answer;		
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		a[i]=i;
	init();
	while(m--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int l, r, x;
			cin>>l>>r>>x;
			update(l, r, x);
		}
		else
		{	
			int l, r;
			cin>>l>>r;
			cout<<query(l, r)<<endl;
		}
	}
	return 0;
}