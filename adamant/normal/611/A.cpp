#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> x;
	string type;
	getline(cin, type);
	if(type.back() == 'k')
	{
		int ans = 51;
		ans += x >= 5;
		ans += x <= 6;
		cout << ans << "\n";
	}
	else
	{
		int ans = 12;
		ans -= x > 29;
		ans -= 4 * (x > 30);
		cout << ans << "\n";
		
	}
	
}