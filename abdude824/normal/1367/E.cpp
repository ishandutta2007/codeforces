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
#define f first
#define s second
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

int32_t main()
{
	aeh();
	W(t)
	{
		int n;
		cin >> n;
		int k;
		cin >> k;
		string s;
		cin >> s;
		//making a frequecy array
		vi arr(26);

		fi(s.size())
		{
			arr[s[i] - 'a']++;
		}
		// fi(26)
		// cout << (char)('a' + i) << " " << arr[i] << endl;
		// retrieving all factors
		vi fact;
		for (int i = 1; i < sqrt(k); i++)
		{
			if (k % i == 0)
			{
				fact.pb(i);
				fact.pb(k / i);
			}
		}
		int g = sqrt(k);
		if (g * g == k)
		{
			fact.pb(g);
		}
		else if (k % g == 0)
		{
			fact.pb(g);
			fact.pb(k / g);
		}

		//Would ask if x number of pairs of y lenth are possible where all elements in each pair is equal
		int m = fact.size();
		vi res;
		fi(m)
		{

			// l pairs of fact[i] length each
			int l = 1;
			int p = l * fact[i];
			while (p <= n)
			{
				int cnt = 0;
				fj(26)
				{
					cnt += arr[j] / l;
				}
				// deb(cnt);
				if (cnt >= fact[i])
				{
					// deb(l);
					res.pb(l * fact[i]);
				}
				l++;
				p = l * fact[i];
			}
		}
		cout << *max_element(all(res)) << endl;
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