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
#define pair pair<int,int>

void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("aana.txt", "r", stdin);
	freopen("jaana.txt", "w", stdout);
#endif
}
int32_t main()
{
	aeh();
	W(t)
	{
		int n; cin >> n;
		vi a(n);
		fi(n)
		cin >> a[i];
		sort(all(a));
		int curr = 1, res = 0;
		for (int i = 0; i < n; i++)
		{
			if (curr == a[i]) {
				res++;
				curr = 1;
			}
			else {
				curr++;
			}
		}
		cout << res << endl;
	}
}