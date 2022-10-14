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
#define F first
#define S second
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
int make_alternate(char a, char b, string s)
{
	int n = s.size();
	bool p1 = false;
	bool p2 = false;
	int cnt = 0;
	fi(n)
	{
		if (s[i] == a && p1 == false)
		{
			p1 = true;
			p2 = false;
			cnt++;
		}
		else if (s[i] == b && p2 == false)
		{
			p2 = true;
			p1 = false;
			cnt++;
		}
	}
	if (cnt % 2)
		cnt--;
	return cnt;
}
int32_t main()
{
	aeh();
	W(t)
	{
		string s;
		cin >> s;
		int n = s.size();
		// deb(n);
		int cnt = 0, rcnt = -1;
		int arr[10] {0};
		fi(n)
		{
			arr[(int)s[i] - '0']++;
		}
		for (char i = '0'; i <= '9'; i++)
		{
			for (char j = i + 1; j <= '9'; j++)
			{
				cnt = max(cnt, make_alternate(i, j, s));
			}
		}
		// deb(make_alternate('2', '5', s));
		fi(10)
		{
			cnt = max(cnt, arr[i]);
		}
		cout << n - cnt << endl;


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