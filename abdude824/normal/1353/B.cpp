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
	freopen("aana.txt", "r", stdin);
	freopen("jaana.txt", "w", stdout);
#endif
}
int32_t main() {
	aeh();
	W(t)
	{
		int n, k; cin >> n >> k;
		vi a(n);
		fi(n)
		cin >> a[i];
		vi b(n);
		fi(n)
		cin >> b[i];
		sort(all(a));
		sort(all(b));
		int i = 0, j = 0;


		while (k--)
		{
			if (i >= n || j >= n)
			{
				break;
			}
			else if (a[i] < b[n - j - 1] )
			{
				int c = a[i];
				a[i] = b[n - j - 1];
				b[n - j - 1] = c;
				i++;
			}
			else {
				j++;
				k++;
			}

		}
		int sum = 0;
		// fi(n)
		// cout << a[i] << ' ' << b[i] << endl;
		fi(n)
		sum += a[i];
		cout << sum << endl;
	}

}