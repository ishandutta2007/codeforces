#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
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
int32_t main()
{
	aeh();
	W(t) {
		int n, k; cin >> n >> k;
		int p = n % 2, z = k % 2;
		if (p == 1 && z == 0)
			cout << "NO" << endl;
		else if (p == 1 || (p == 0 && z == 0)) {
			if (k - 1 >= n)
				cout << "NO" << endl;
			else {
				cout << "YES" << endl;
				for (int i = 0; i < k - 1; i++)
					cout << "1 ";
				cout << n - k + 1 << endl;
			}
		}
		else {
			if ((k - 1) * 2 >= n)
				cout << "NO" << endl;
			else {
				cout << "YES" << endl;
				for (int i = 0; i < k - 1; i++)
					cout << "2 ";
				cout << n - 2 * k + 2 << endl;
			}
		}

	}
}