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

int hashs[100005];
int getHashs(int l, int r)
{
	return (hashs[r] - hashs[l - 1]) % mod;
}
int ans = -1;
int solve(vector<int>&a, int l, int r)
{
	int n = sz(a);
	int p, mn = INT_MAX;
	if (l == n - 1)
		return a[n - 1];
	if (r == -1)
		return 0;
	if (r == 0)
		return a[0];
	for (int i = l; i <= r; i++)
	{
		if (mn > a[i]) {
			mn = a[i];
			p = i;
		}
	}
	ans = max(ans, mn * (r - l + 1));
	ans = max(ans, solve(a, l, p - 1));
	ans = max(ans, solve(a, p + 1, r));
	return ans;
}

int32_t main()
{
	aeh();
	W(t)
	{
		int n;
		cin >> n;
		vi a(n);
		int diff = -1;
		int mx = -INT_MAX;
		fi(n)
		{
			cin >> a[i];
		}
		fi(n)
		{
			if (a[i] > mx)
				mx = a[i];
			else
				diff = max(diff, mx - a[i]);
		}
		int a1 = 0, p = 1;
		int cnt = 0;
		while (a1 < diff)
		{
			cnt++;
			a1 = a1 + p;
			p = p * 2;
		}
		cout << cnt << endl;
	}
}