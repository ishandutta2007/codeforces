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
int primeFactors(int n)
{
	int fl = 0;
	int curr = 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		// cout << i << endl;
		while (n % i == 0 && n > 1)
		{
			fl = 1;
			n /= i;
			curr = i;
		}
		if (fl && n > 1)
			return 0;
		else if (fl)
			return curr;
	}
	return 0;
}
int no_of_factors(int n)
{
	int cnt = 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			cnt += 2;
	}
	if (sqrt(n) == n)
		cnt--;
	// if (cnt == 0)
	// 	cnt++;
	return cnt;
}
int32_t main()
{
	aeh();
	int n; cin >> n;
	int no = no_of_factors(n);
	if (no)
	{
		if (no == 1)
			cout << no << endl;
		else
		{
			// cout << primeFactors(n) << endl;
			if (primeFactors(n))
			{
				cout << primeFactors(n) << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
	}
	else
		cout << n << endl;
}