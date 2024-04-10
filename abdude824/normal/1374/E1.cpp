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
int32_t main()
{
	aeh();
	// W(t/)
	// {
	int n, k;
	cin >> n >> k;
	vi ab, a, b;
	fi(n)
	{
		int a1, b1, c1;
		cin >> a1 >> b1 >> c1;
		if (b1 && c1)
			ab.pb(a1);
		else if (b1)
			a.pb(a1);
		else if (c1)
			b.pb(a1);
	}
	sortall(ab);
	sortall(b);
	sortall(a);
	int x1 = sz(ab);
	int x2 = sz(b);
	int x3 = sz(a);
	// fi(x3)
	// cout << a[i] << " ";
	// cout << endl;
	// fi(x1)
	// cout << ab[i] << " ";
	// cout << endl;
	// fi(x2)
	// cout << b[i] << " ";
	// cout << endl;

	int i1 = 0, i2 = 0, i3 = 0;
	int ans = 0;
	if (x2 == 0 || x3 == 0)
	{
		if (x1 < k)
			cout << -1 << endl;
		else
		{
			fi(k)
			{
				ans += ab[i];
			}
			cout << ans << endl;
		}
	}
	else if (x1 == 0)
	{
		if (min(x2, x3) < k)
			cout << -1 << endl;
		else {
			fi(k)
			{
				ans += a[i] + b[i];
			}
			cout << ans << endl;
		}
	}
	else {

		while (k)
		{
			if (i1 >= x1 && (i2 >= x3 || i3 >= x2)) {
				ans = -1;
				break;
			}

			// if (i1 >= x1)
			// {
			// 	i1 = x1 - 1;
			// 	ab[i1] = inf;
			// }
			// else if (i2 >= x3)
			// {
			// 	i2 = x3 - 1;
			// 	a[i2] = inf;
			// }
			// else if (i3 >= x2)
			// {
			// 	i3 = x3 - 1;
			// 	b[i3] = inf;
			// }
			int c1, c2;
			if (i1 < x1)
				c1 = ab[i1];
			else c1 = inf;
			if (i2 < x3 && i3 < x2)
				c2 = a[i2] + b[i3];
			else
				c2 = inf;
			// deb(c1);
			// deb(c2);
			// deb(c1);
			if (c1 <= c2)
			{
				ans += c1;
				k -= 1;
				i1++;
			}
			else
			{
				ans += c2;
				k -= 1;
				i2++;
				i3++;
			}
		}
		cout << ans << endl;
	}
	// }
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