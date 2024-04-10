#include <iostream>

using namespace std;

string s[100];
int main()
{
	string a = "YES";
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			int b = 0;
			if(j < n - 1 && s[i][j + 1] == 'o')
			{
				b += 1;
			}
			if(j > 0 && s[i][j - 1] == 'o')
			{
				b += 1;
			}
			if(i < n - 1 && s[i + 1][j] == 'o')
			{
				b += 1;
			}
			if(i > 0 && s[i - 1][j] == 'o')
			{
				b += 1;
			}
			if(b % 2 == 1)
			{
				a = "NO";
			}
		}
		
		
	}
	cout << a;
	return 0;
}