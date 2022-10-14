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
int32_t main()
{
	aeh();
	W(t)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		set<int> zer, one;
		fi(n)
		{
			if (s[i] == '0')
				zer.insert(i);
			else
				one.insert(i);
		}
		vi res(n);
		int k = 1;
		while (one.size() != 0 && zer.size() != 0)
		{
			int curr = *(zer.begin());
			bool turn = false;
			if (*(one.begin()) < * (zer.begin())) {
				curr = *(one.begin());
				turn = true;
			}
			while (true)
			{

				if (turn)
				{
					if (zer.upper_bound(curr) != zer.end())
					{
						int temp = curr;
						res[curr] = k;
						one.erase(curr);
						res[*(zer.upper_bound(curr))] = k;
						curr = *(zer.upper_bound(curr));
						zer.erase(*zer.upper_bound(temp));
						// deb(curr);
						turn = false;
					}
					else {
						k++;
						break;
					}
				}
				else
				{
					if (one.upper_bound(curr) != one.end())
					{
						int temp = curr;
						res[curr] = k;
						res[*(one.upper_bound(curr))] = k;
						zer.erase(curr);
						curr = *(one.upper_bound(curr));
						one.erase(*one.upper_bound(temp));
						// deb(curr);
						turn = true;

					}
					else
					{
						k++;
						break;
					}
				}
			}
		}
		k--;
		if (one.size())
		{
			for (auto it : one) {
				k++;
				res[it] = k;
			}
		}
		if (zer.size())
		{
			for (auto it : zer) {
				k++;
				res[it] = k;
			}
		}
		cout << k << endl;
		fi(n)
		cout << res[i] << " ";
		cout << endl;
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