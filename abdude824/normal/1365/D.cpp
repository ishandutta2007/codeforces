#include<bits/stdc++.h>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define fo(i,a,n) for(int i=a;i<n;i++)
#define vi vector<int>
#define vs vector<string>
// #define int long long int
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
char a[51][51];
int dp[100][100];
void check(int i, int j, int n, int m)
{
	if (i >= n || j >= m || i < 0 || j < 0)
		return ;
	if (a[i][j] == '#')
		return ;
	if (dp[i][j])
		return;
	dp[i][j] = 1;
	check(i + 1, j, n, m); check(i - 1, j, n, m); check(i, j + 1, n, m); check(i, j - 1, n, m);
}

int main()
{
	aeh();
	W(t)
	{
		fi(100)
		{
			fj(100)
			{
				dp[i][j] = 0;
			}
		}

		int n, m;
		cin >> n >> m;
		int fl = 0;
		fi(n)
		{
			fj(m)
			{
				cin >> a[i][j];
				if (a[i][j] == 'G')
					fl = 1;
			}
		}
		int f = 0;
		if (fl)
		{
			fi(n)
			{
				fj(m)
				{
					if (a[i][j] == 'B')
					{
						if (a[min(n - 1, i + 1)][j] == 'G' || a[max(0, i - 1)][j] == 'G' || a[i][min(m - 1, j + 1)] == 'G' || a[i][max(0, j - 1)] == 'G')
						{
							f = 1;

							break;
						}
						if (a[min(n - 1, i + 1)][j] == '.')
							a[min(n - 1, i + 1)][j] = '#';
						if (a[max(0, i - 1)][j] == '.')
							a[max(0, i - 1)][j] = '#';
						if (a[i][min(m - 1, j + 1)] == '.') a[i][min(m - 1, j + 1)] = '#';
						if (a[i][max(0, j - 1)] == '.') a[i][max(0, j - 1)] = '#';
					}
				}
				if (f)
					break;
			}
			if (f)
			{
				cout << "NO" << endl;
				continue;
			}
			else
			{
				int g = 0;
				if (a[n - 1][m - 1] != '#')
					check(n - 1, m - 1, n, m);
				fi(n)
				{
					fj(m)
					{
						if (a[i][j] == 'G')
						{
							if (dp[i][j] == 0)
							{
								cout << "NO" << endl;
								g = 1;
								i = n;
								break;
							}
						}
					}
				}
				if (!g) {
					cout << "YES" << endl;
					continue;
				}
			}
		}
		else
		{
			if (a[n - 1][m - 1] != 'B')
			{
				cout << "YES" << endl;
			}
			else
				cout << "NO" << endl;
		}
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