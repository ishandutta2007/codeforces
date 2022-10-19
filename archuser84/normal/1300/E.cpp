#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	FAST;
	int n;
	int a[1000000];
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	vector<pair <long double, int>> b;
	LoopR(i, 0, n)
	{
		b.push_back({ a[i],1 });
		LoopR(j, 1, b.size())
		{
			if (b[j].first < b[j - 1].first)
				break;
			b[j - 1].first = (b[j].first * b[j].second + b[j - 1].first * b[j - 1].second) / (b[j].second + b[j - 1].second);
			b[j - 1].second += b[j].second;
			b.pop_back();
		}
	}
	LoopR(i, 0, b.size())
		Loop(j, 0, b[i].second)
			printf("%0.9f\n", b[i].first);
}