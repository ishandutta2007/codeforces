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
		int a; int k;
		cin >> a >> k;
		k--;
		for (int i = 0; i < k; i++)
		{
			string g = to_string(a);
			int b = *min_element(g.begin(), g.end()) - '0';
			int c = *max_element(g.begin(), g.end()) - '0';
			// int g = stoi(a);
			// g = g + (b * c);
			// a = to_string(g);
			a = a + b * c;
			if (b == 0)
				break;
		}
		cout << a << endl;
	}
}