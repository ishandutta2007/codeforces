#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		bool A[26][26] = { 0 };
		int D[26] = { 0 };
		int m = 0;
		char s[1000];
		cin >> s;
		int size = strlen(s);
		bool ans = 1;
		Loop(i, 0, size - 1)
		{
			int a = s[i] - 'a';
			int b = s[i + 1] - 'a';
			if (!A[a][b])
			{
				A[a][b] = true;
				A[b][a] = true;
				D[a]++;
				D[b]++;
				m++;
				if (D[a] > 2 || D[b] > 2)
				{
					ans = false;
					break;
				}
			}
		}
		vector<int> path;
		if (ans && m!=0)
		{
			int count = 0;
			int k = -1;
			Loop(i, 0, 26)
			{
				if (D[i] == 1)
				{
					k = i;
					path.push_back(k);
					break;
				}
			}
			if (k == -1)
			{
				ans = false;
				goto END;
			}
			int pk = -1;
			do
			{
				Loop(i, 0, 26)
				{
					if (i != pk && A[k][i] == 1)
					{
						pk = k;
						k = i;
						path.push_back(k);
						break;
					}
				}
				count++;
			} while (D[k] > 1);
			if (count != m)
				ans = false;
		}
		END:
		if (ans)
		{
			cout << "YES\n";
			bool ped[26] = { 0 };
			for (int i : path)
			{
				ped[i] = true;
				printf("%c", i + 'a');
			}
			Loop(i, 0, 26)
			{
				if (!ped[i])
					printf("%c", i + 'a');
			}
			cout << endl;
		}
		else
			cout << "NO\n";
	}
}