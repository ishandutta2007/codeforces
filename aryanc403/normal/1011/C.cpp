//Author http://codeforces.com/contest/1011/submission/40852363
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define PI atan(1)/4
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;
#define debug4(x,y,z,zz) cout << x << " " << y << " " << z <<" "<<zz << endl;
#define epsilon 1e-7

using namespace std;

void solve();
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#endif
	int t = 1;
	//cin >> t;
	WL(t) solve();
}

void solve()
{
	int n,m;
	cin >> n >> m;
	int a[n];
	int b[n];
	REP(i,n) cin >> a[i];
	REP(i,n) cin >> b[i];
	double l = 0,r = 1e9;
	double fuel = -1;
	int ff = 1e9;
	for(int i=0;i<n;++i)
	{
	    if(a[i]==1||b[i]==1)
    	{
		    debug(-1);
		    return;
	    }
	}
	FOR(i,1,2*n)
	{
		int index = i/2;
		int abi = i%2;
		double ab;
		if(abi==1)//a
		{
			ab = a[index];
		}
		else //b
			ab = b[index];
		ff-=((m+ff)/ab);
	}
	ff-=((m+ff)/b[0]);
	while(l<=r)
	{
		double mid = (l+r)/2;
		double f = mid;
		FOR(i,1,2*n)
		{
			int index = i/2;
			int abi = i%2;
			double ab;
			if(abi==1)//a
			{
				ab = a[index];
			}
			else //b
				ab = b[index];
			f-=((m+f)/ab);
		}
		f-=((m+f)/b[0]);
		if((f==0)||((fabs(r-l)<epsilon)))
		{
			fuel = mid;
			break;
		}
		double nl,nr;
		if(f<0)
		{
			//More Fuel
			nl = mid;
			nr = r;
		}
		else
		{
			//Less Fuel
			nl = l;
			nr = mid;
		}
		l = nl;
		r = nr;
	}
	cout << setprecision(10) << fixed;
	debug(fuel);
}