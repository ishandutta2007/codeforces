#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		map<int, unsigned int> x;
		int sum = 0;
		int n;
		cin >> n;
		for (LoopN)
		{
			int y;
			cin >> y;
			int two = 0;
			while (y % 2 == 0)
			{
				y /= 2;
				++two;
			}
			if (x[y] < two)
			{
				sum += two - x[y];
				x[y] = two;
			}
		}
		cout << sum << '\n';
	}
}