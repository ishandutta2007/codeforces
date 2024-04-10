/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
//typedef double f80;
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=95542721;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

const int N=100005;
int a[N];
int sum[4*N][48],lazy[4*N];
void build(int seg, int lb, int rb)
{
	if(lb!=rb)
	{
		build(seg*2,lb,(lb+rb)/2);
		build(seg*2+1,(lb+rb)/2+1,rb);
		for(int i=0; i<48; i++)
			sum[seg][i]=(sum[seg*2][i]+sum[seg*2+1][i])%mod;
	}
	else
	{
		sum[seg][0]=a[lb]%mod;
		for(int i=1; i<48; i++)
			sum[seg][i]=(((sum[seg][i-1]*sum[seg][i-1])%mod)*sum[seg][i-1])%mod;
	}
}
void pushdown(int seg, int lb, int rb)
{
	if(lb!=rb&&lazy[seg])
	{
		rotate(sum[seg*2],sum[seg*2]+lazy[seg],sum[seg*2]+48);
		rotate(sum[seg*2+1],sum[seg*2+1]+lazy[seg],sum[seg*2+1]+48);
		lazy[seg*2]=(lazy[seg*2]+lazy[seg])%48;
		lazy[seg*2+1]=(lazy[seg*2+1]+lazy[seg])%48;
		lazy[seg]=0;
	}
}
int query(int seg, int lb, int rb, int l, int r)
{
	if(lb>r||l>rb)
		return 0;
	if(l<=lb&&rb<=r)
		return sum[seg][0];
	pushdown(seg,lb,rb);
	return (query(seg*2,lb,(lb+rb)>>1,l,r)+query(seg*2+1, ((lb+rb)>>1)+1, rb, l, r));
}
void update(int seg, int lb, int rb, int l, int r)
{
	if(lb>r||l>rb)
		return;
	if(l<=lb&&rb<=r)
	{
		rotate(sum[seg],sum[seg]+1,sum[seg]+48);
		lazy[seg]=(lazy[seg]+1)%48;
		return;
	}
	pushdown(seg,lb,rb);
	update(seg*2,lb,(lb+rb)>>1,l,r);
	update(seg*2+1,((lb+rb)>>1)+1,rb,l,r);
	for(int i=0; i<48; i++)
		sum[seg][i]=(sum[seg<<1][i]+sum[seg<<1|1][i])%mod;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	build(1,1,n);
	int q;
	cin>>q;
	int ty,l,r;
	while(q--)
	{
		cin>>ty>>l>>r;
		if(ty==1)
			cout<<(query(1,1,n,l,r)%mod)<<endl;
		else
			update(1,1,n,l,r);
	}
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	clk=clock()-clk;
	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
#endif
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