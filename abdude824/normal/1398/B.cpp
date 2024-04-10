// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// (`v)
// `..Coding


/*       *********
 *       *
 *   *   *   *
 *       *
 *****************
         *       *
     *   *   *   *
         *       *
 *********       */
#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ll long long int
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define W(x) int x;cin>>x;while(x--)
#define fr(n) for(int i=n-1;i>=0;i--)
#define mp make_pair
#define fo(i,a,n) for(int i=a;i<n;i++)
#define ps(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define vi vector<int>
#define deb(x) cout<<#x<<"="<<x<<endl;
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define sortall(x) sort(all(x))
#define mk(arr,n,type)  type *arr=new type[n];
#define vpi vector<pair<int,int> >
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define sz(x) (int)x.size()
#define vs vector<string>
#define itr(a) for(auto it=a.begin();it!=a.end();it++)
#define f first
#define s second
#define INT_SIZE 32
int mpow(int exp, int base);
//I don't know what the funciton aeh() does but it speeds up my mess
void aeh()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int count_ones(string &s)
{
	int fst = 0, fend = s.size() - 1, st = -1, cnt = 0, fcnt = 0;
	fi(s.size())
	{
		if (s[i] == '1')
		{
			if (st == -1)
			{
				st = i;
			}
			cnt++;
		}
		else
		{
			if (fcnt < cnt)
			{
				fcnt = cnt;
				fst = st;
				fend = i;
			}
			st = -1;
			cnt = 0;

		}
	}
	// deb(fcnt);
	if (cnt > fcnt) {
		fcnt = cnt;
		// cout << "h";
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == '0') {
				st = i + 1;
				break;
			}
		}
		fst = st;
		fend = s.size() - 1;
	}
	// deb(fst);
	// deb(fend);
	s.erase(fst, -fst + fend + 1);
	// deb(s);
	return fcnt;
}
int32_t main()
{
	aeh();
	W(t)
	{
		string s;
		cin >> s;
		int n = s.size(); bool al = true; int ali = 0, bob = 0;
		while (s.size())
		{
			if (al)
			{
				ali += count_ones(s);
				al = false;
			}
			else
			{
				al = true;
				bob += count_ones(s);
			}
			int fl = 0;
			fi(s.size())
			if (s[i] == '1')
				fl = 1;
			if (!fl)
				break;

		}
		cout << ali << endl;
	}
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