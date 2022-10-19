#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n == 1)
	{
		cout << "NO";
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (s[i] != s[i - 1])
		{
			cout << "YES" << endl;
			cout << s[i - 1] << s[i];
			return 0;
		}
	}
	cout << "NO";
	return 0;
}