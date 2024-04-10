#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, k;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		bool flag = 1;
		for(int i = 0; i < k; i++)
		{
			bool have0 = 0, have1 = 0;
			for(int j = i; j < n; j += k)
			{
				have0 |= (s[j] == '0');
				have1 |= (s[j] == '1');
			}
			if(have0 && have1)
				flag = 0;
			else if(have0 || have1)
			{
				for(int j = i; j < n; j += k)
				{
					if(have0)
						s[j] = '0';
					else
						s[j] = '1';
				}
			}
		}
		if(!flag)
			cout << "NO" << endl;
		else
		{
			int sum = 0, ques = 0;
			for(int i = 0; i < k; i++)
			{
				if(s[i] == '1')
					sum++;
				else if(s[i] == '0')
					sum--;
				else
					ques++;
			}
			flag &= (ques >= abs(sum) && (ques - abs(sum)) % 2 == 0);
			if(flag)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}