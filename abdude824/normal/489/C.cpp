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
#define f first
#define s second
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
bool can(int m, int n)
{
	return m >= 0 && m <= 9 * n;
}
int32_t main()
{
	aeh();
	int n, m; cin >> n >> m;
	int base = n * 9;
	if (m == 0 && n != 1)
		cout << "-1 -1" << endl;
	else if (m > base)
		cout << "-1 -1" << endl;
	else {
		int m1 = m, n1 = n;
		for (int i = 0; i <= 9; i++)
		{
			if (n == 1)
			{
				if (can(m - i, n) && m - i == 0)
				{
					cout << i;
					break;
				}
			}
			if (n1 == n && i == 0)
			{
				continue;
			}
			if (can(m - i, n - 1))
			{
				cout << i;
				m -= i;
				i = -1;
				n--;
			}
			// deb(i);
		}
		cout << " ";
		for (int i = 9; i >= 0; i--)
		{
			if (n1 == 1)
			{
				if (can(m1 - i, n1) && m1 - i == 0)
				{
					cout << i;
					break;
				}
			}
			if (can(m1 - i, n1 - 1))
			{
				cout << i;
				m1 -= i;
				i = 10;
				n1--;
			}
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