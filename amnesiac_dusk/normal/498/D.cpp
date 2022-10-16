/*
 * :(
 * You taught me so much, I'm not scared anymore
 * 	I have to left go your hands that are holding me
 * 	 Even if I'm alone, I'll go on, even if it hurts
 * 	  I'll never forget the dream, I shared with you
 * 	   I'm glad to be with everyone, I'm glad to have been with everyone
 * 	    But on the morning when I wake up, no one is there
 */
//#define opti
#ifdef opti
#define min(x, y) (y ^ ((x ^ y) & -(x < y)))
#define max(x, y) (x ^ ((x ^ y) & -(x < y)))
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif
#ifndef opti
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
#define holadeb cout<<"Line: "<<__LINE__<<" "<<pls<<" "
typedef long long ll;
const ll mod=1000000007;
//const ll mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);
int imul[60][7];
int sad[60][300000];
void update(int seg,int lb, int rb,int point, int mul)
{
	if(lb>point||rb<point)
		return;
	if(lb==rb)
	{
		for(int i=0; i<60; i++)
			sad[i][seg]=imul[i][mul];
		return;
	}
	update(seg*2,lb,(lb+rb)/2,point,mul);
	update(seg*2+1,(lb+rb)/2+1,rb,point,mul);
	for(int i=0; i<60; i++)
		sad[i][seg]=sad[i][seg*2]+sad[(i+sad[i][seg*2])%60][seg*2+1];
}
int query(int seg, int lb, int rb,int l, int r,int time)
{
	if(lb>r||rb<l)
		return 0;
	if(l<=lb&&r>=rb)
		return sad[time][seg];
	int te=query(2*seg,lb,(lb+rb)/2,l,r,time);
	return te+query(2*seg+1,(lb+rb)/2+1,rb,l,r,(time+te)%60);
}
void solve()
{
	int n,te;
	cin>>n;
	for(int i=0; i<60; i++)
		for(int j=1; j<=6; j++)
			imul[i][j]=(i%j==0)+1;
	for(int i=1; i<=n; i++)
	{
		cin>>te;
		update(1,1,n,i,te);
	}
	int q;
	cin>>q;
	char a;
	int b,c;
	while(q--)
	{
		cin>>a>>b>>c;
		if(a=='A')
			cout<<query(1,1,n,b,c-1,0)<<endl;
		else
			update(1,1,n,b,c);
	}
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifdef rd
		clock_t clk = clock();
	#endif
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	#ifdef rd
		clk = clock() - clk;
		cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
	#endif
	return 0;
}
ll powm(ll a,ll b, ll m)
{
	ll te=1;
	while(b)
	{
		if(b&1)
			te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}