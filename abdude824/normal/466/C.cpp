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
int32_t main()
{
	aeh();
	int n;
	cin >> n;
	vi a(n);
	int sum = 0;
	fi(n) {
		cin >> a[i];
		sum += a[i];
	}
	vi b(n);
	b[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	if (sum % 3 || n < 3)
		cout << 0 << endl;
	else {
		int ans = 0, c = 0;
		int s = 0;
		int s1 = sum / 3, s2 = 2 * sum / 3;
		fi(n - 1)
		{
			s += a[i];
			if (s == s2)
				ans += c;
			if (s == s1)
				c++;
		}
		cout << ans << endl;
	}
}