#include <iostream>

using namespace std;

string s[500005];
string t[500005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> s[i];
	}
	t[n - 1] = s[n - 1];
	for(int i = n - 1; i > 0; i --)
	{
		
		t[i - 1] += '#';
		int j = 1;
		while(j < s[i].size() && j < s[i - 1].size() && s[i - 1][j] <= t[i][j])
		{
			if(s[i - 1][j] < t[i][j])
			{
				t[i - 1] = s[i - 1];
				break;
			}
			t[i - 1] += s[i - 1][j];
			j ++;
		}
	}
	for(int i = 0; i < n; i ++)
	{
		cout << t[i] << endl;
	}
	return 0;
}