#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) cout<<(flag?"YES\n":"NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 1e5 + 10;

int main()
{
	FAST;
	vector<int> A[N];
	int n;
	int a = 0, b = 1, c = 2;
	cin >> n;
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(i);
		A[v].push_back(i);
	}
	Loop(i, 0, n)
	{
		if (A[i].size() > 2)
		{
			a = A[i][0];
			b = A[i][1];
			c = A[i][2];
			break;
		}
	}
	int p = 3;
	Loop(i, 0, n - 1)
	{
		if (i == a)
			cout << "0\n";
		else if (i == b)
			cout << "1\n";
		else if (i == c)
			cout << "2\n";
		else
			cout << p++ << '\n';
	}
}