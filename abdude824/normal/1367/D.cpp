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


int32_t main()
{
	aeh();
	W(t)
	{
		string s;
		cin >> s;
		int m;
		cin >> m;
		vi a(m);
		fi(m)
		cin >> a[i];
		int n = s.size();
		int arr[26];
		fi(26)
		arr[i] = 0;
		fi(n)
		{
			arr[s[i] - 'a']++;
		}
		// cout << endl;
		char p[m];
		vi vis(m, 0);
		int cnt = 1;
		int k = 25;
		while (true)
		{
			vi zero;
			for (int i = 0; i < m; i++)
			{
				if (a[i] == 0 && vis[i] == 0)
				{
					zero.pb(i);
				}
			}
			if (zero.size() == 0)
				break;
			else
			{
				for (int i = k; i >= 0; i--)
				{
					if (arr[i] >= zero.size())
					{
						for (int j = 0; j < zero.size(); j++)
						{
							p[zero[j]] = 'a' + i;
							vis[zero[j]] = 1;
						}
						arr[i] = 0;
						k = i;
						break;
					}
				}
				for (int i = 0; i < m; i++)
				{
					if (a[i] != 0)
					{
						for (int j = 0; j < zero.size(); j++)
							a[i] = a[i] - abs(i - zero[j]);
					}
				}
			}
		}
		fi(m)
		cout << p[i];
		cout << endl;

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