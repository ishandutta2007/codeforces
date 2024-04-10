#include <iostream>
using namespace std;

char s[102];
int a[30];
int main()
{
	int i, k, n, m=0;
	char e;
	cin >> s;
	n = strlen(s);
	for (i = 0; i < n; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			e = s[i] - 'A' + 'a';
			s[i] = e;
		}
		k = s[i] - 'a';
		a[k]++;
	}
	for (i = 0; i < 28;i++)
	{
		if (a[i] > 0)
			m++;
	}
	if (m % 2 == 1)
	{
		cout << "IGNORE HIM!" << endl;
		return 0;
	}
	cout << "CHAT WITH HER!" << endl;
	return 0;
}