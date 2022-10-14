// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// (`v)
// `..Coding


/*       *********
 *       *
 *   *   *   *
 *       *
 *****************
         *       *
     *   *   *   *
         *       *
 *********       */
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define F first
#define S second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int32_t main()
{
	aeh();
	W(t)
	{
		int n, k, z;
		cin >> n >> k >> z;
		vi a(n);
		fi(n)
		cin >> a[i];
		int cnt = -1;
		bool t1 = false;
		vi rss(n), lss(n);
		rss[0] = a[0];
		for (int i = 1; i < n; i++)
		{
			rss[i] = rss[i - 1] + a[i];
		}
		lss[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			lss[i] = a[i] + lss[i + 1];
		}
		// fi(n)
		// cout << rss[i] << " ";
		// cout << endl;
		// fi(n)
		// cout << lss[i] << " ";
		// cout << endl;

		fi(n - 1)
		{
			int mov = i;
			int left = k - mov;
			if (left < 0)
				break;
			int d;
			d = rss[i];

			if (left < 2 * z)
			{
				d += (left / 2) * (a[i] + a[i + 1]);
				if (left % 2)
				{
					d += a[i + 1];
				}
			}
			else {
				d -= a[i];
				d += z * (a[i] + a[i + 1]);
				left = left - 2 * z;
				d += lss[i] - lss[i + left] + a[i + left];
			}
			cnt = max(d, cnt);
		}
		if (n == 1)
		{
			cnt = a[0];
		}
		cout << cnt << endl;
	}

}


int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}