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

		string s; cin >> s;
		int n = s.size();
		vi res;
		int cnt = 1;
		int	st = 0;
		for (int i = 1; i < n - 1; i++) {
			if (s[i + 1] == s[i])
			{
				cnt++;
			}
			else {
				if (cnt == 1)
				{
					if (s[i - 1] != s[i + 1] && s[i - 1] != s[i])
					{
						res.pb(cnt);
					}
				}
				if (cnt > 1) {
					if (s[st] != s[i + 1] && s[st] != s[i])
					{
						res.pb(cnt);
					}
					cnt = 1;
				}
				st = i;
			}
		}
		if (sz(res) == 0)
			cout << 0 << endl;
		else {
			cout << *min_element(all(res)) + 2 << endl;
		}
	}
}