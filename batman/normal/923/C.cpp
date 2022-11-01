#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)301*1000)
#define K ((ll)31)

struct Node
{
	ll cnt,e[2];
	Node(){cnt=0;e[0]=e[1]=-1;}
};

ll n,a[N],sz=1;
Node b[N*K];

void add(ll x)
{
	ll now=0;
	for(int i=K-1;i>=0;i--)
	{
		bool p=(x&(1<<i));
		if(b[now].e[p]==-1)b[now].e[p]=sz,sz++;
		b[now].cnt++;
		now=b[now].e[p];
	}
	b[now].cnt++;
}

ll query(ll x)
{
	ll now=0,num=0;
	for(int i=K-1;i>=0;i--)
	{
		bool p=(x&(1<<i));
		b[now].cnt--;
		if(b[now].e[p]!=-1 && b[b[now].e[p]].cnt>0)
			now=b[now].e[p],num*=2;
		else now=b[now].e[!p],num*=2,num++;
	}
	b[now].cnt--;
	return num;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int j=0;j<n;j++)
	{
		ll x;cin>>x;
		add(x);
	}
	for(int i=0;i<n;i++)
		cout<<query(a[i])<<" ";
	cout<<"\n";
	return 0;
}