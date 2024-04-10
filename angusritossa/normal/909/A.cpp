#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n, m;
char str1[20], str2[20];
int main()
{
	scanf(" %s %s", str1, str2);
	n = strlen(str1);
	m = strlen(str2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			string s;
			for (int k = 0; k <= i; k++) s.push_back(str1[k]);
			for (int k = 0; k <= j; k++) s.push_back(str2[k]);
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end());
	cout << v[0] << '\n';
}