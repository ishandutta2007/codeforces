#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i);
#define ET cout << "\n";
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET}
using namespace std;

struct node
{
	ll sz=0;
	node *l=0,*r=0; // l:0 r:1
};

ll sz(node *p)
{
	return p ? p->sz : 0;
}

void push(node *&p,int n,int k)
{
	if(!p) p=new node;
	if(k==0)
	{
		p->sz++;
		return;
	}
	ll tmp=(1<<(k-1));
	if(tmp&n) push(p->r,n,k-1);
	else push(p->l,n,k-1);
	p->sz=sz(p->l)+sz(p->r);
}

int query(int n,int k,node *&p,int t)
{
	if(k==0)
	{
		delete p;
		p=0;
		return t;
	}
	ll tmp=(1<<(k-1)),re=0;
	if(tmp&n)
	{
		if(p->l) re=query(n,k-1,p->l,t<<1);
		else re=query(n,k-1,p->r,t<<1^1);  
	}
	else
	{
		if(p->r) re=query(n,k-1,p->r,t<<1^1);
		else re=query(n,k-1,p->l,t<<1);
	}
	p->sz--;
	if(!p->sz)
	{
		delete p;
		p=0;
	}
	return re;
}

ll ans[1000001];

int main()
{
	node *p=0;
	ll n,i,ANS=0;
	cin >> n;
	for(i=0;i<=n;i++)
		push(p,i,20);
	for(i=n;i>=0;i--)
		ans[i]=query(i,20,p,0),ANS+=ans[i]^i;
	for(cout << ANS << "\n",i=0;i<=n;i++)
		if(i==n) cout << ans[i] << "\n";
		else cout << ans[i] << " ";
}