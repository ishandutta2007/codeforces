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
bool check_kro(int two, int four, int six, int eight)
{
	if (eight)
		return true;
	if (six && two)
		return true;
	if (six && four)
		return true;
	if (six >= 2)
		return true;
	if (four >= 2)
		return true;
	if (four && two >= 2)
		return true;
	return false;
}
int32_t main()
{
	aeh();
	// W(t)
	// {
	int n;
	vi arr(100001);
	cin >> n;
	vi a(n);
	fi(n)
	cin >> a[i];
	fi(n)
	{
		arr[a[i]]++;
	}
	int q;
	cin >> q;
	int eight = 0, two = 0, four = 0, six = 0;
	fi(arr.size())
	{
		if (arr[i] >= 8)
			eight++;
		else if (arr[i] >= 6)
			six++;
		else if (arr[i] >= 4)
			four++;
		else if (arr[i] >= 2)
			two++;
	}
	// deb(eight);
	// deb(six);
	// deb(four);
	// deb(two);
	while (q--)
	{
		char c;
		cin >> c;
		if (c == '+')
		{
			int g;
			cin >> g;
			arr[g]++;
			if (arr[g] == 8) {
				eight++;
				six--;
			}
			else if (arr[g] == 4) {
				four++;
				two--;
			}
			else if (arr[g] == 6) {
				six++;
				four--;
			}
			else if (arr[g] == 2)
				two++;
			if (check_kro(two, four, six, eight))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else {

			int g;
			cin >> g;
			arr[g]--;
			if (arr[g] == 7) {
				eight--;
				six++;
			}
			else if (arr[g] == 3) {
				four--;
				two++;
			}
			else if (arr[g] == 5) {
				six--;
				four++;
			}
			else if (arr[g] == 1)
				two--;
			if (check_kro(two, four, six, eight))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	// }
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