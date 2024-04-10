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

int32_t main()
{
	aeh();
	W(t)
	{
		int a, b;
		cin >> a >> b;
		if (b < a)
		{
			int c = b;
			b = a;
			a = c;
		}
		if (b >= a)
		{
			if (b % a)
			{
				cout << -1 << endl;

			}
			else {
				if (b == a)
				{
					cout << 0 << endl;
				}
				else if ((b / a) % 2)
				{
					cout << -1 << endl;
				}
				else
				{
					int p = b / a;
					{

						int cnt1 = 0;
						int a = p;
						while (a % 8 == 0 && a != 1)
						{
							a /= 8;
							cnt1++;
						}
						if (a == 1)
						{
							cout << cnt1 << endl;
						}
						else {
							while (a % 4 == 0 && a != 1)
							{
								a /= 4;
								cnt1++;
							}
							if (a == 1)
							{
								cout << cnt1 << endl;
							}
							else {
								while (a % 2 == 0 && a != 1)
								{
									a /= 2;
									cnt1++;
								}
								if (a == 1)
								{
									cout << cnt1 << endl;
								}
								else
								{
									cout << -1 << endl;
								}
							}
						}
					}
				}
			}
		}
	}
}