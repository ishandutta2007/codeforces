#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vs vector<string>
#define int long long int
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("aana.txt", "r", stdin);
	freopen("jaana.txt", "w", stdout);
#endif
}

int32_t main() {
	aeh();
	W(t)
	{
		int n; cin >> n;
		int res = 0;
		if (n == 2)
			cout << "2\n";
		else {
			for (int i = 1; i <= (n / 2) - 1; i++)
			{
				res += pow(2, i);
			}
			for (int i = n / 2; i <= n - 1; i++)
			{
				res -= pow(2, i);
			}
			res += pow(2, n);
			cout << res << endl;
		}
	}
}