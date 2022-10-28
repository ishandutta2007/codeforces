#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = (1LL<<17) + 5;

int n, m;
int a[N+5], st[4*N];

void build(int node, int L, int R, int parity)
{
	if(L==R)
	{
		st[node]=a[L];
		return;
	}
	int M=(L+R) >> 1;
	build(node+node,L,M,parity^1);
	build(node+node+1,M+1,R,parity^1);
	if(parity)
	{
		st[node]=st[node+node] | st[node+node+1];
	}
	else
	{
		st[node]=st[node+node] ^ st[node+node+1];
	}
}

void update(int node, int L, int R, int pos, int newval, int parity)
{
	if(L==R)
	{
		st[node]=newval;
		return;
	}
	int M=(L+R)>>1;
	if(pos<=M)
		update(node+node,L,M,pos,newval,parity^1);
	else
		update(node+node+1,M+1,R,pos,newval,parity^1);
	if(parity)
	{
		st[node]=st[node+node] | st[node+node+1];
	}
	else
	{
		st[node]=st[node+node] ^ st[node+node+1];
	}
}
int main()
{
	IOS;
	cin>>n>>m;
	int sz=1<<n;
	for(int i=0;i<sz;i++)
	{
		cin>>a[i];		
	}
	build(1, 0, sz-1, n&1);
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		a--;
		update(1, 0, sz-1, a, b, n&1);
		cout<<st[1]<<endl;
	}
	return 0;
}