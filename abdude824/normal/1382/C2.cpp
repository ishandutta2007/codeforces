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
vi a;
vi a1;
void convert_to_zeroes(string s)
{
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			a.pb(i);
			a.pb(i + 1);
		}
	}
}
void convert_to_string(string s)
{
	int n = s.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '1')
		{
			a.pb(i + 1);
			a.pb(i);
		}
	}
}
void convert_to_ones(string s)
{
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			a1.pb(i);
			a1.pb(i + 1);

		}
	}
}
void convert_to_string1(string s)
{
	int n = s.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '0')
		{
			a1.pb(i + 1);
			a1.pb(i);
		}
	}
}
int32_t main()
{
	aeh();
	W(t)
	{
		fi(a.size())
		a[i] = 0;
		fi(a1.size())
		a1[i] = 0;
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1;
		cin >> s2;
		if (s1 == s2)
			cout << 0 << endl;
		else {
			int cnto = 0, cntz = 0;
			fi(n)
			{
				if (s1[i] == '1')
					cnto++;
				else
					cntz++;
			}
			convert_to_ones(s1);
			convert_to_string1(s2);
			convert_to_zeroes(s1);
			convert_to_string(s2);
			int cnt = 0;
			int cnt1 = 0;
			for (int i = 0; i < a.size(); i++)
			{
				if (a[i] != 0)
					cnt++;
			}
			for (int i = 0; i < a1.size(); i++)
			{
				if (a1[i] != 0)
					cnt1++;
			}
			if (cnt < cnt1)
			{
				cout << cnt << " ";
				for (int i = 0; i < a.size(); i++)
				{
					if (a[i])
						cout << a[i] << " ";
				}
				cout << endl;
			}
			else
			{
				cout << cnt1 << " ";
				for (int i = 0; i < a1.size(); i++)
				{
					if (a1[i])
						cout << a1[i] << " ";
				}
				cout << endl;
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