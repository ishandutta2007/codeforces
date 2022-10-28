#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		string a = "", b = "";
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
			{
				if(i == 0)
				{
					a += '2';
					b += '1';
				}
				else
				{
					a += '0';
					b += '0';
				}
			}
			else if(s[i] == '1')
			{
				if(a < b)
				{
					a += '1';
					b += '0';
				}
				else
				{
					a += '0';
					b += '1';
				}
			}
			else
			{
				if(a == b)
				{
					a += '1';
					b += '1';
				}
				else if(a < b)
				{
					a += '2';
					b += '0';
				}
				else
				{
					a += '0';
					b += '2';
				}
			}
		}
		cout << a << endl;
		cout << b << endl;
	}
	return 0;
}