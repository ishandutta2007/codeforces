#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define chlo(i,a,n) for(int i=a;i<n;i++)
#define vi vector<int>
#define vs vector<string>
#define int long long int
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define sz(x) (int)x.size()
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define INT_SIZE 32
#define pr pair<int,int>
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("aana.txt", "r", stdin);
	freopen("jj.txt", "w", stdout);
#endif
}
//chliye bakchodi shuru krte hain
//ek tu hi yaar mera mughko kya duniya se lena
int32_t main()
{
	aeh();
	int n;
	cin >> n;
	vi f(n);
	fi(n)
	cin >> f[i];

	vi a(n);
	fi(n)
	{
		if (f[i] != 0)
			a[f[i] - 1] = 1;
	}
	int p = -1;
	fi(n)
	{
		if (a[i] != 1)
		{
			if (f[i] != 0)
			{
				p = i;
			}

		}
	}
	fi(n)
	{
		if (a[i] != 1)
		{
			if (f[i] != 0)
			{
				p = i;
			}
			else {
				if (p != -1)
				{
					f[i] = p + 1;
					a[f[i] - 1] = 1;
					p = i;
				}
				else {
					p = i;
				}
			}
		}
	}

	vi res;
	fi(n)
	{
		if (a[i] == 0)
			res.pb(i);
	}
	int x = 0;
	fi(n)
	{
		if (f[i] == 0)
		{
			f[i] = res[x] + 1;
			x++;
		}
	}


	fi(n)
	cout << f[i] << " ";

}