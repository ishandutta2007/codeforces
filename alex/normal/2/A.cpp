#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define seta(a, b) memset(a, b, sizeof(a))

char name[1001][50], tmp[50];
int n, m, num, sum[1001], ans[1001], ansn[1001];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> n;
	m = 0;
	forn(i, n)
	{
		cin >> tmp >> num;
		bool find = false;
		forn(j, m)
			if (strcmp(name[j], tmp) == 0)
			{
				sum[j] += num;
				find = true;
				ans[i] = sum[j];
				ansn[i] = j;
			}
		if (!find)
		{
			forn(j, strlen(tmp))
				name[m][j] = tmp[j];
			sum[m] = num;
			ans[i] = sum[m];
			ansn[i] = m;
			m++;
		}
	}
	
	int who = 0;
	num = 0;
	forn(i, m)
	{
		if (sum[who] < sum[i]) who = i;
		if (sum[who] == sum[i]) num++;
	}
		
	if (num == 1) { cout << name[who] << endl; return 0; }
	
	forn(i, n)
		if (ans[i] >= sum[who] && sum[ansn[i]] == sum[who])
		{
			cout << name[ansn[i]] << endl;
			return 0;
		}

	return 0;
}