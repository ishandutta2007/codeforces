#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1111;

string a[MAXN];
string s;
int n, m, d;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while (getline(cin, s))
	{
		a[n++] = s;
		m = max(m, (int)s.size());
	}

	for (int i = -2; i < m; i++)
		printf("*");
	printf("\n");


	d = 0;
	for (int i = 0; i < n; i++)
	{
		int k = m - (int)a[i].size();
		printf("*");
		for (int j = 0; j < (k + d) / 2; j++)
			printf(" ");
		printf("%s", a[i].c_str());

		for (int j = (k + d) / 2; j < k; j++)
		printf(" ");

		printf("*");
		printf("\n");

		if (k & 1) d = 1 - d;
	}

	for (int i = -2; i < m; i++)
		printf("*");
	printf("\n");
	return 0;
}