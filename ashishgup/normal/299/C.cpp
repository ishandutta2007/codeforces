#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e6 + 5;
 
int n, sA = 0, sB = 0;
int common = 0, first = 0, second = 0;
string a, b;
 
int32_t main()
{
	IOS;
	cin >> n >> a >> b;
	for(int i = 0; i < 2 * n; i++)
	{
		if(a[i] == '1' && b[i] == '1')
			common++;
		else if(a[i] == '1')
			first++;
		else if(b[i] == '1')
			second++;
	}
	for(int i = 1; i <= 2 * n; i++)
	{
		if(i % 2)
		{
			if(common > 0)
			{
				sA++;
				common--;
			}
			else if(first > 0)
			{
				sA++;
				first--;
			}
			else
				second--;
		}
		else
		{
			if(common > 0)
			{
				sB++;
				common--;
			}
			else if(second > 0)
			{
				sB++;
				second--;
			}
			else
				first--;
		}
	}
	if(sA > sB)
		cout << "First";
	else if(sA == sB)
		cout << "Draw";
	else
		cout << "Second";
	return 0;
}