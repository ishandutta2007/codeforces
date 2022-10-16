/*
* 	When the sun shines, we shine together
* 		Told you I'll be here forever
* 			Said I'll always be your friend
* 				Took an oath that I'm a stick it out till the end
* 	Now that it's raining more than ever
* 		Know that we still have each other
* 			You can stand under my umbrella
* 				You can stand under my umbrella, ella, ella, eh, eh, eh
* 	This one: https://www.youtube.com/watch?v=pFOinFPctHs :D
*/
//#pragma GCC optimize("Ofast,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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
#define all(x) x.begin(),x.end()
#define shuffle(a,b) random_shuffle(a,b,rng)
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);


vector<pii> points;
pii temp[2][2][2];
pii tempo[8];
int area(int i, int j, int k)
{
	int are=abs(points[i].fi-points[j].fi)+abs(points[i].se-points[j].se);
	are+=abs(points[i].fi-points[k].fi)+abs(points[i].se-points[k].se);
	are+=abs(points[k].fi-points[j].fi)+abs(points[k].se-points[j].se);
	return are;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1,x,y; i<=n; i++)
	{
		cin>>x>>y;
		points.pb({x,y});
	}
	int maxx=points[1].fi,maxy=points[1].se;
	int minx=points[1].fi,miny=points[1].se;
	for(int i=0,x,y; i<n; i++)
	{
		x=points[i].fi;
		y=points[i].se;
		maxx=max(x,maxx);
		maxy=max(y,maxy);
		miny=min(y,miny);
		minx=min(x,minx);
	}
	int ans=area(0,1,2);
	for(int i=0,j=1,k=2; i<n;)
	{
		if(area(i%n,j%n,(k+1)%n)>area(i%n,j%n,k%n))
			k++;
		else if(area(i%n,(j+1)%n,k%n)>area(i%n,j%n,k%n))
			j++;
		else
			i++;
		ans=max(ans,area(i%n,j%n,k%n));
	}
	for(int i=0; i<8; i++)
		tempo[i]=points[0];
	for(int i=0; i<8; i++)
			temp[i&1][(i&2)>>1][(i&4)>>2]=points[1];
		for(int i=0; i<n; i++)
		{
			if(tempo[0].fi+tempo[0].se>points[i].fi+points[i].se||(tempo[0].fi<points[i].fi&&tempo[0].fi+tempo[0].se==points[i].fi+points[i].se))
				tempo[0]=points[i];
			if(tempo[1].fi+tempo[1].se>points[i].fi-points[i].se||(tempo[1].fi<points[i].fi&&tempo[1].fi+tempo[1].se==points[i].fi-points[i].se))
				tempo[1]=points[i];
			if(tempo[2].fi+tempo[2].se<points[i].fi-points[i].se||(tempo[2].fi<points[i].fi&&tempo[2].fi+tempo[2].se==points[i].fi-points[i].se))
				tempo[2]=points[i];
			if(tempo[3].fi+tempo[3].se<points[i].fi+points[i].se||(tempo[3].fi<points[i].fi&&tempo[3].fi+tempo[3].se==points[i].fi+points[i].se))
				tempo[3]=points[i];
			if(tempo[4].fi+tempo[4].se>points[i].fi+points[i].se||(tempo[4].fi>points[i].fi&&tempo[4].fi+tempo[4].se==points[i].fi+points[i].se))
				tempo[4]=points[i];
			if(tempo[5].fi+tempo[5].se>points[i].fi-points[i].se||(tempo[5].fi>points[i].fi&&tempo[5].fi+tempo[5].se==points[i].fi-points[i].se))
				tempo[5]=points[i];
			if(tempo[6].fi+tempo[6].se<points[i].fi-points[i].se||(tempo[6].fi>points[i].fi&&tempo[6].fi+tempo[6].se==points[i].fi-points[i].se))
				tempo[6]=points[i];
			if(tempo[7].fi+tempo[7].se<points[i].fi+points[i].se||(tempo[7].fi>points[i].fi&&tempo[7].fi+tempo[7].se==points[i].fi+points[i].se))
				tempo[7]=points[i];
			if(temp[0][0][0].fi>=points[i].fi)
			{
				if(temp[0][0][0].fi>points[i].fi)
				{
					temp[0][0][0]=points[i];
					temp[0][0][1]=points[i];
				}
				else
				{
					temp[0][0][0]=min(temp[0][0][0],points[i]);
					temp[0][0][1]=max(temp[0][0][1],points[i]);
				}
			}
			if(temp[0][1][0].fi<=points[i].fi)
			{
				if(temp[0][1][0].fi<points[i].fi)
				{
					temp[0][1][0]=points[i];
					temp[0][1][1]=points[i];
				}
				else
				{
					temp[0][1][0]=min(temp[0][1][0],points[i]);
					temp[0][1][1]=max(temp[0][1][1],points[i]);
				}
			}
			if(temp[1][0][0].se>=points[i].se)
			{
				if(temp[1][0][0].se>points[i].se)
				{
					temp[1][0][0]=points[i];
					temp[1][0][1]=points[i];
				}
				else
				{
					temp[1][0][0]=min(temp[1][0][0],points[i]);
					temp[1][0][1]=max(temp[1][0][1],points[i]);
				}
			}
			if(temp[1][1][0].se<=points[i].se)
			{
				if(temp[1][1][0].se<points[i].se)
				{
					temp[1][1][0]=points[i];
					temp[1][1][1]=points[i];
				}
				else
				{
					temp[1][1][0]=min(temp[1][1][0],points[i]);
					temp[1][1][1]=max(temp[1][1][1],points[i]);
				}
			}
		}

		vector<pii> pp;
		for(int i=0; i<8; i++)
			{
			//		cout<<(i&1)<<" "<<((i&2)>>1)<<" "<<((i&4)>>2)<<" ";
			//		cout<<temp[i&1][(i&2)>>1][(i&4)>>2].fi<<" ";
			//		cout<<temp[i&1][(i&2)>>1][(i&4)>>2].se<<endl;
				pp.pb(temp[i&1][(i&2)>>1][(i&4)>>2]);
			}for(int i=0; i<8; i++)
			{
			//		cout<<(i&1)<<" "<<((i&2)>>1)<<" "<<((i&4)>>2)<<" ";
			//		cout<<temp[i&1][(i&2)>>1][(i&4)>>2].fi<<" ";
			//		cout<<temp[i&1][(i&2)>>1][(i&4)>>2].se<<endl;
				pp.pb(tempo[i]);
			}
		for(int i=0; i<16; i++)
			for(int j=0; j<16; j++)
				for(int k=0; k<n; k++)
				{
					int te=abs(pp[i].fi-pp[j].fi)+abs(pp[i].se-pp[j].se);
					te+=abs(pp[i].fi-points[k].fi)+abs(pp[i].se-points[k].se);
					te+=abs(points[k].fi-pp[j].fi)+abs(points[k].se-pp[j].se);
					ans=max(ans,te);
				}
		if(n<500)
		{
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++)
					for(int k=j+1; k<n; k++)
					{
						int te=abs(points[i].fi-points[j].fi)+abs(points[i].se-points[j].se);
						te+=abs(points[i].fi-points[k].fi)+abs(points[i].se-points[k].se);
						te+=abs(points[k].fi-points[j].fi)+abs(points[k].se-points[j].se);
						ans=max(ans,te);
					}
		}
	cout<<ans<<" ";
	for(int i=4; i<=n; i++)
		cout<<(2*(maxy-miny+maxx-minx))<<" ";
}
signed main()
{
	IO;
	srand(chrono::steady_clock::now().time_since_epoch().count());
	#ifdef rd
//		clock_t clk = clock();
	#endif
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	#ifdef rd
//		clk = clock() - clk;
//		cout<<endl<<endl<< "Time Elapsed: " << fixed << setprecision(10) << ((double)clk)/CLOCKS_PER_SEC <<endl;
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