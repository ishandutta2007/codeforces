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
#define INT_SIZE 32
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int32_t main() {
	aeh();
	W(t) {
		int n; cin >> n;
		int a[n + 1];
		int f[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			f[i] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i * 2; j <= n; j += i)
			{
				if (a[i] < a[j])
					f[j] = max(f[j], f[i] + 1);
			}
		}
		int max = -1;
		for (int i = 1; i <= n; i++)
		{
			if (max < f[i])
				max = f[i];
		}
		cout << max << endl;

	}


}