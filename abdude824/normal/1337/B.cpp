#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
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
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define sz(x) (int)x.size()
#define mp make_pair
#define msi multiset<int>
#define INT_SIZE 32
#define pair pair<int,int>

void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("aana.txt", "r", stdin);
	freopen("jj.txt", "w", stdout);
#endif
}
int32_t main()
{
	aeh();
	W(t)
	{
		int x, n, m; cin >> x >> n >> m;
		int fl = 1;
		while (x > 0)
		{
			if (x > 19 && n > 0) {
				x = (x / 2) + 10;
				n--;
			}
			else if (x <= 19 && m > 0) {
				x = x - 10;
				m--;
			}
			else if (n == 0)
			{
				if (n == 0 && m > 0)
				{
					x = x - 10;
					m--;
				}

			}
			else if (m == 0)
			{
				if (m == 0 && n > 0)
				{
					x = (x / 2) + 10;
					n--;
				}
			}
			if (n == 0 && m == 0 && x > 0)
			{
				fl = 0;
				cout << "NO" << endl;
				break;
			}
		}
		if (fl)
			cout << "YES" << endl;
	}
}