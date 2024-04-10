#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100000;
vector<int> A[N];
int s[N] = {};
int k[N] = {};

int main()
{
	FAST;
	int t;
	cin >> t;
	bool present[N];
	bool alone[N];
	while (t--)
	{
		int n;
		cin >> n;
		Loop(i, 0, n)
		{
			s[i] += k[i];
			cin >> k[i];
			Loop(j, 0, k[i])
			{
				int x;
				cin >> x;
				A[i].push_back(x-1);
			}
		}
		Loop(i, 0, n)
		{
			present[i] = false;
			alone[i] = true;
		}
		int cnt = 0;
		Loop(i, 0, n)
		{
			Loop(j, s[i], s[i] + k[i])
			{
				if (!present[A[i][j]])
				{
					present[A[i][j]] = true;
					alone[i] = false;
					cnt++;
					break;
				}
			}
		}
		if (cnt == n)
			cout << "OPTIMAL\n";
		else
		{
			int a, b;
			Loop(i, 0, n)
				if (alone[i])
				{
					a = i + 1;
					break;
				}
			Loop(i, 0, n)
				if (!present[i])
				{
					b = i + 1;
					break;
				}
			cout << "IMPROVE\n";
			cout << a << ' ' << b << '\n';
		}
	}
}