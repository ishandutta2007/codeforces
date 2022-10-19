#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopN int i = 0; i < n; ++i
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n;
	char s[200001];
	cin >> n >> s;
	bool ans = true;
	int c = 0;
	for(LoopN)
	{
		if (s[i] == '(')
			c++;
		else
			c--;
		if (c == -2)
			break;
	}
	cout << (c == 0 ? "Yes" : "No") << '\n';
}