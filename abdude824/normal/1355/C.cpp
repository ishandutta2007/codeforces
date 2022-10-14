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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == b && b == c && c == d) {
		cout << 1 << endl;
	}
	else {

		int ps[b + c + 2];
		fi(b + c + 2)
		ps[i] = 0;
		for (int i = a; i <= b; i++) {
			int mn = i + b;
			int mx = i + c;
			ps[mn]++;
			ps[mx + 1]--;
		}
		for (int i = 1; i < b + c + 2; i++)
		{
			ps[i] = ps[i - 1] + ps[i];
		}

		int s = b + c + 2;
		int cnt = 0;
		for (int i = b + c + 1; i >= 0; i--) {
			if (ps[i] == 0)
				continue;
			else {
				if (i <= c)
					break;
				else {
					if (i > d)
						cnt = cnt + ps[i] * (d - c + 1);
					else
						cnt = cnt + ps[i] * (i - c);
					// cout << cnt << endl;
				}
			}
		}
		cout << cnt << endl;
	}
}