//Started 2 mins late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int32_t main()
{
	IOS;
	int a, b, k;
	cin >> a >> b >> k;
	if(k == 0)
	{
		string ans = "";
		for(int i = 1; i <= b; i++)
			ans += "1";
		for(int i = 1; i <= a; i++)
			ans += "0";
		cout << "Yes" << endl;
		cout << ans << endl;
		cout << ans << endl;
	}
	else if(k == a + b)
		cout << "No" << endl;
	else if(b == 1)
	{
		if(k != 0)
			cout << "No" << endl;
		else
		{
			cout << "Yes" << endl;
			string ans = "1";
			for(int i = 1; i <= a; i++)
				ans += "0";
			cout << ans << endl;
			cout << ans << endl;
		}
	}
	else if(a == 0)
	{
		if(k != 0)
			cout << "No" << endl;
		else
		{
			cout << "Yes" << endl;
			string ans = "";
			for(int i = 1; i <= b; i++)
				ans += "1";
			cout << ans << endl;
			cout << ans << endl;
		}
	}
	else
	{
		int n = a + b;
		if(k >= a + b - 1)
		{
			cout << "No";
			return 0;
		}
		string s = "1";
		string t = "1";
		int first = a + b - 2 - k;
		b--;
		a--;
		b--;
		for(int i = 1; i <= first; i++)
		{
			if(a > 0)
				s += "0", t += "0", a--;
			else
				s += "1", t += "1", b--;
		}
		s += "1", t += "0";
		while(s.size() + 1 < n)
		{
			if(a > 0)
				s += "0", t += "0", a--;
			else
				s += "1", t += "1", b--;
		}
		s += "0", t += "1";
		cout << "Yes" << endl;
		cout << s << endl;
		cout << t << endl;
	}
	return 0;
}