#include <iostream>

using namespace std;

string a[105];
int main()
{
	int n, m;
	string s = "YES";
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 1; j < m; j ++)
		{
			if(a[i][j] != a[i][j - 1])
			{
				s = "NO";
			}
		} 
		if(i > 0 && a[i][0] == a[i - 1][0])
		{
			s = "NO";
		}
	}
	cout << s;
	return 0;
}