#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;
const int M=(1LL<<4)+5;

int n, k, q;
int a[N][6];
int st[M][4*N], st2[M][4*N];

void build(int node, int idx, int L, int R)
{
	if(L==R)
	{
		for(int j=0;j<5;j++)
		{
			if(idx>>j & 1)
				st[idx][node]+=a[L][j];
			else
				st[idx][node]-=a[L][j];
		}
		return;
	}
	int M=(L+R)/2;
	build(node*2, idx, L, M);
	build(node*2+1, idx, M+1, R);
	st[idx][node]=min(st[idx][node*2], st[idx][node*2+1]);
}

int query(int node, int idx, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return 1e9;
	if(i<=L && R<=j)
		return st[idx][node];
	int M=(L+R)/2;
	int left=query(node*2, idx, L, M, i, j);
	int right=query(node*2 + 1, idx, M+1, R, i, j);
	return min(left, right);
}

void update(int node, int idx, int L, int R, int pos, int val)
{
	if(L==R)
	{
		st[idx][node]=0;
		for(int j=0;j<5;j++)
		{
			if(idx>>j & 1)
				st[idx][node]+=a[L][j];
			else
				st[idx][node]-=a[L][j];
		}
		return;
	}
	int M=(L+R)/2;
	if(pos<=M)
		update(node*2, idx, L, M, pos, val);
	else
		update(node*2 + 1, idx, M+1, R, pos, val);
	st[idx][node]=min(st[idx][node*2], st[idx][node*2 + 1]);
}

void build2(int node, int idx, int L, int R)
{
	if(L==R)
	{
		for(int j=0;j<5;j++)
		{
			if(idx>>j & 1)
				st2[idx][node]+=a[L][j];
			else
				st2[idx][node]-=a[L][j];
		}
		return;
	}
	int M=(L+R)/2;
	build2(node*2, idx, L, M);
	build2(node*2+1, idx, M+1, R);
	st2[idx][node]=max(st2[idx][node*2], st2[idx][node*2+1]);
}

int query2(int node, int idx, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return -1e9;
	if(i<=L && R<=j)
		return st2[idx][node];
	int M=(L+R)/2;
	int left=query2(node*2, idx, L, M, i, j);
	int right=query2(node*2 + 1, idx, M+1, R, i, j);
	return max(left, right);
}

void update2(int node, int idx, int L, int R, int pos, int val)
{
	if(L==R)
	{
		st2[idx][node]=0;
		for(int j=0;j<5;j++)
		{
			if(idx>>j & 1)
				st2[idx][node]+=a[L][j];
			else
				st2[idx][node]-=a[L][j];
		}
		return;
	}
	int M=(L+R)/2;
	if(pos<=M)
		update2(node*2, idx, L, M, pos, val);
	else
		update2(node*2 + 1, idx, M+1, R, pos, val);
	st2[idx][node]=max(st2[idx][node*2], st2[idx][node*2 + 1]);
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<(1<<4);i++)
	{
		build(1, i, 1, n);
		build2(1, i, 1, n);
	}
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int idx;
			cin>>idx;
			for(int j=0;j<k;j++)
				cin>>a[idx][j];
			for(int i=0;i<(1<<4);i++)
			{
				update(1, i, 1, n, idx, idx);
				update2(1, i, 1, n, idx, idx);
			}
		}
		else
		{
			int l, r;
			cin>>l>>r;
			int ans=0;
			for(int i=0;i<(1<<4);i++)
				ans=max(ans, query2(1, i, 1, n, l, r) - query(1, i, 1, n, l, r));
			cout<<ans<<endl;
		}
	}
	return 0;
}