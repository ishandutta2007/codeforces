//#define opti
#ifdef opti
//#pragma GCC optimize("Ofast,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3,unroll-loops")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "<<endl
typedef long long ll;
const ll inf=5e9;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);
int a[1000001];
struct node
{
	int prefsum,sum;
	int lb,rb;
	node *left,*right;
	node(int lb, int rb):lb(lb),rb(rb)
	{
		if(lb==rb)
		{
			sum=a[lb];
			prefsum=a[lb];
			left=NULL;
			right=NULL;
		}
		else
		{
			left=new node(lb,(lb+rb)>>1);
			right=new node(((lb+rb)>>1)+1,rb);
			prefsum=min(left->prefsum,left->sum+right->prefsum);
			sum=left->sum+right->sum;
		}
	}
	int sumq(int t)
	{
		if(rb<=t)
			return sum;
		if(lb>t)
			return 0;
		return left->sumq(t)+right->sumq(t);
	}
	int minpref(int t)
	{
		if(rb<=t)
			return prefsum;
		if(lb>t)
			return inf;
		return min(left->minpref(t),left->sum+right->minpref(t));
	}
	void update(int i)
	{
		if(lb>i||rb<i)
			return;
		if(lb==rb)
		{
			prefsum=a[lb];
			sum=a[lb];
		}
		else
		{
			left->update(i);
			right->update(i);
			prefsum=min(left->prefsum,left->sum+right->prefsum);
			sum=left->sum+right->sum;
		}
	}
};
pii queries[300001];
void solve()
{
	for(int i=1; i<=1000000; i++)
		a[i]=-1;
	node* seg=new node(1,1000000);
	int q;
	cin>>q;
	char te;
	for(int i=1; i<=q; i++)
	{
		cin>>te;
		if(te=='+')
		{
			int t,d;
			cin>>t>>d;
			queries[i]={t,d};
			a[t]+=d;
			seg->update(t);
		}
		else if(te=='-')
		{
			int num;
			cin>>num;
			a[queries[num].fi]-=queries[num].se;
			seg->update(queries[num].fi);
		}
		else
		{
			int t;
			cin>>t;
			int ans=1+seg->sumq(t)-min(0LL,seg->minpref(t-1));
			cout<<ans<<endl;
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
//	int t=1;
//	cin>>t;
//	ii=1e9-1e4;
//	for(;ii<1e9; ii++)
//	{
//		clock_t clk = clock();
		solve();
//		clk = clock() - clk;
//		if(((double)clk)/CLOCKS_PER_SEC>1)
//		{
//			printf("%lld\n",ii);
//		}
//	}
//#ifdef rd
//	cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) <<  <<endl;
//#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}