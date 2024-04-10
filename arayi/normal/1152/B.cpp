#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
using lli = long long int;
using namespace std;
const int N = 4000010;
const int mod = 1000000;
int x;
int lg[N];
int sm = 0;
vector <int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	for (int i = 1; i < N; i++)
	{
		if ((1 << sm) == i)
		{
			sm++;
		}
		lg[i] = sm;
	}
	cin >> x;
	int pat = 0;
	int i = 1;
	while (x != (1 << lg[x]) - 1)
	{
		if (i % 2 == 0)
			x++;
		else
		{
			for (int i = lg[x] - 1; i >= 0; i--)
			{
				if (!((1 << i) & x))
				{
					x = (x ^ ((1 << (i + 1)) - 1));
					
					ans.push_back(i + 1);
					break;
				}
			}
		}
		//cout << x << " ";
		i++;
	}
	cout << i - 1 << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}