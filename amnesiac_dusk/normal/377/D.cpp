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
//#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
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

int lvr[100001];
pii a[1200001];
int lazy[1200001];
inline void pushdown(int seg, int lb, int rb)
{
	if(lb==rb)
	{
		a[seg].se=lb;
		return;
	}
	if(lazy[seg])
	{
		a[seg*2].fi+=lazy[seg];
		a[seg*2+1].fi+=lazy[seg];
		lazy[seg*2]+=lazy[seg];
		lazy[seg*2+1]+=lazy[seg];
		lazy[seg]=0;
	}
}
void update(int seg, int lb, int rb, int l, int r, int val)
{
	if(l>rb||r<lb)
		return;
	if(l<=lb&&rb<=r)
	{
		a[seg].fi+=val;
		lazy[seg]+=val;
		return;
	}
	pushdown(seg,lb,rb);
	update(seg*2, lb,(lb+rb)/2, l, r, val);
	update(seg*2+1,(lb+rb)/2+1,rb, l, r, val);
	a[seg]=max(a[seg*2],a[seg*2+1]);
}
bool active[100001];
bool answ[100001];
int tola[100001][3];
void solve()
{
	int n;
	cin>>n;
	vector<pair<pii,pii>> add,rem;
	int l,v,r;
	for(int i=1; i<=n; i++) {
		cin>>l>>v>>r;
		tola[i][0]=l;
		tola[i][1]=v;
		tola[i][2]=r;
		add.pb({{v,i},{l,v}});
		rem.pb({{r,i},{l,v}});
	}
	sort(all(add));
	sort(all(rem));
	int ans=0;
	add.pb({{inf,inf},{inf,inf}});
	rem.pb({{inf,inf},{inf,inf}});
	for(int i=0,j=0; i<=n&&j<n; ) {
		if(add[i].fi.fi<=rem[j].fi.fi) {
			update(1,1,300000,add[i].se.fi, add[i].se.se,1);
			ans=max(ans,a[1].fi);
			i++;
		}
		else {
			update(1,1,300000,rem[j].se.fi,rem[j].se.se,-1);
			j++;
		}
	}
	cout<<ans<<endl;
	for(int i=0,j=0; i<n; ) {
		if(add[i].fi.fi<=rem[j].fi.fi) {
			update(1,1,300000,add[i].se.fi, add[i].se.se,1);
			active[add[i].fi.se]=1;
			if(ans==a[1].fi)
			{
//				cout<<i<<" "<<j<<endl;
				int teans=0;
				vector<pii> ls,rs;
				for(int i=1; i<=n; i++)
					if(active[i]) {
						ls.pb({tola[i][0],i});
						rs.pb({tola[i][1],i});
					}
				sort(all(ls));
				sort(all(rs));
//				cout<<ls.size()<<" "<<rs.size()<<endl;
				for(int i=0,j=0; i<ls.size();)
				{
					if(ls[i].fi<=rs[j].fi)
					{
						answ[ls[i].se]=1;
						teans++;
						i++;
					}
					else
					{
						answ[rs[j].se]=0;
						teans--;
						j++;
					}
//					deb<<teans<<endl;
					if(teans==ans)
					{
						for(int k=1; k<=n; k++)
							if(answ[k])
								cout<<k<<" ";
						return;
					}
				}
				return;
			}
			i++;
		}
		else {
			update(1,1,300000,rem[j].se.fi,rem[j].se.se,-1);
			active[rem[j].fi.se]=0;
			j++;
		}
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