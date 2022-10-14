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
#define sortall(x) sort(all(x))
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define sz(x) (int)x.size()
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setpr1ecision(y)<<x
#define mp make_pair
#define INT_SIZE 32
#define pr pair<int,int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define F first
#define S second
#define pii pair<int,int>

int mpow(int exp, int base);
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("aana.txt", "r", stdin);
	freopen("jj.txt", "w", stdout);
#endif
}

#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>

#define loop(l, r) for(int i = l;i <= r;++i)
#define loopj(l, r) for(int j = l;j <= r;++j)
#define loopStep(l, r, step) for(int i = l;(step >= 0 ? (i <= r) : (i >= r));i += step)
#define loopStepj(l, r, step) for(int j = l;(step >= 0 ? (j <= r) : (j >= r));j += step)
#define loopRange(el, container) for(auto &el : container)

#define test int t;cin >> t; while(t--)

#define ENDL << "\n"

using namespace std;

int32_t main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;

	if (n <= m)
	{
		loop(1, n)
		cout << "GB";
		loop(1, m - n)
		cout << "G";
	}
	else
	{
		loop(1, m)
		cout << "BG";
		loop(1, n - m)
		cout << "B";
	}

	cout ENDL;

	return 0;
}
int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}