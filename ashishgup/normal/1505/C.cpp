#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long
 
const int N = 3005;
 
int32_t main()
{
	IOS;
	string str;
	cin >> str;
	int flag = 1;
	for(int i = 2; i < str.size(); i++)
	{
		int a = str[i - 2] - 'A';
		int b = str[i - 1] - 'A';
		int cur = (a + b) % 26;
		if((str[i] - 'A') != cur)
			flag = 0;
	}
	if(flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}