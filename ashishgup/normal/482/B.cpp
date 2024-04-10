#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, null;
int a[N], st[4*N], arr[32][N];

struct data
{
	int l, r, k;
};

data store[N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=a[L];
		return;
	}
	int M=(L+R)>>1;
	build(node*2, L, M);
	build(node*2 + 1, M+1, R);
	st[node]=st[node*2] & st[node*2  +1];
}

int query(int node, int L, int R, int i, int j)
{
	if(j<L || i>R)
		return ((1LL<<31)-1);
	if(i<=L && R<=j)
	{
		return st[node];
	}
	int M=(L+R)>>1;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return (left&right);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int l, r, k;
		cin>>l>>r>>k;
		store[i].l=l;
		store[i].r=r;
		store[i].k=k;
		for(int j=30;j>=0;j--)
		{
			if(k&(1LL<<j))
			{
				arr[j][l]+=1;
				arr[j][r+1]-=1;;
			}
		}
	}
	for(int j=30;j>=0;j--)
	{
		for(int i=1;i<=n;i++)
		{
			arr[j][i]+=arr[j][i-1];
			if(arr[j][i]>0)
				a[i]+=(1LL<<j);
		}
	}
	build(1, 1, n);
	for(int i=1;i<=m;i++)
	{
		int cur=query(1, 1, n, store[i].l, store[i].r);
		if(cur!=store[i].k)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}