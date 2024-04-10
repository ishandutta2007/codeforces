#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == '>')
		{
			break;
		}
		cnt++;
	}
	for(int i = n - 1; i >= 0; --i)
	{
		if(s[i] == '<')
		{
			break;
		}
		++cnt;
	}
	cout << cnt << endl;
	
	return 0;
}