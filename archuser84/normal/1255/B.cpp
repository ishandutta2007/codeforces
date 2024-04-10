#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int n,m;
		cin >> n >> m;
		int sum=0;
		for(LoopN)
		{
			int x;
			cin >> x;
			sum += x;
		}
		if(n<3)
			cout << "-1\n";
		else if(m<n)
			cout << "-1\n";
		else
		{
			cout << 2*sum << '\n';
			for(int i=1;i<n;++i)
				cout << i << ' ' << i+1 << '\n';
			cout << n << " 1\n";
		}
	}
}