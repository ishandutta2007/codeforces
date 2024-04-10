#include<bits/stdc++.h>

using namespace std;

#define int long long int
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
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int arr[8001], is[8001]; //is will tell if ith number is special or not
int32_t main()
{
	aeh();
	W(t)
	{
		int n;
		cin >> n;
		vi a;
		if (n <= 3)
			cout << -1 << endl;
		else if (n > 3)
		{
			int m = n;
			int j = 1;
			while (j <= n)
			{
				a.pb(j);
				j += 2;
			}
			if (m % 2)
				m--;
			while (m >= 1)
			{
				a.pb(m);
				m -= 2;
			}
			if (n % 2 == 0)
			{
				swap(a[n / 2 - 1], a[n / 2 - 2]);
			}
			else
			{
				// swap(a[n / 2], a[n / 2 - 1]);
				swap(a[n / 2 + 1], a[n / 2 + 2]);
			}
			// swap(a[n / 2 + 1], a[n / 2 + 2]);
			for (auto it : a)
			{
				if (it <= 0)
					continue;
				cout << it << " ";
			}
			cout << endl;
		}
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