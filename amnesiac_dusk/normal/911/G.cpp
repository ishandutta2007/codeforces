//#define opti
#ifdef opti
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#else
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
//#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

char hola[524288][101];
void pushdown(int seg)
{
	for(int i=1; i<=100; i++)
	{
		hola[seg<<1][i]=hola[seg][hola[seg<<1][i]];
		hola[seg<<1|1][i]=hola[seg][hola[seg<<1|1][i]];
	}
	for(int i=1; i<=100; i++)
		hola[seg][i]=i;
}
void query(int seg, int lb, int rb,int l, int r, int fr, int to)
{
	if(rb<l||lb>r)
		return;
	if(l<=lb&&r>=rb)
	{
		for(int i=1; i<=100; i++)
			if(hola[seg][i]==fr)
				hola[seg][i]=to;
		return;
	}
	pushdown(seg);
	query(seg<<1, lb, (lb+rb)>>1, l, r, fr, to);
	query(seg<<1|1, ((lb+rb)>>1)+1, rb, l, r, fr, to);
}
char a[200001];
void pushpush(int seg,int lb, int rb)
{
	if(lb!=rb)
	{
		pushdown(seg);
		pushpush(seg<<1, lb,(lb+rb)>>1);
		pushpush(seg<<1|1,((lb+rb)>>1)+1,rb);
	}
	else
		a[lb]=hola[seg][a[lb]];
}
void solve()
{
	int n,te;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>te;
		a[i]=te;
	}
	for(int i=1; i<524288; i++)
		for(int j=1; j<=100; j++)
			hola[i][j]=j;
	int q;
	cin>>q;
	int l,r,x,y;
	while(q--)
	{
		cin>>l>>r>>x>>y;
		query(1, 1, n, l, r, x, y);
	}
	pushpush(1,1,n);
	for(int i=1; i<=n; i++)
		cout<<(int)a[i]<<" ";
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	clock_t clk = clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	clk = clock() - clk;
	fflush(stdout);
#ifdef rd
	cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
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