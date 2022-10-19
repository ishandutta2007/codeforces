#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define mek static_cast<long long>(1)

char a[100003];
long long n, l;

long long m;
bool lr;
void stg()
{
	for (long long i = 0; i < l; ++i)
	{
		if ((n - (mek << i)) >= 0 && (n - (mek << i)) % (mek << (i + mek)) == 0)
		{
			m = i;
			lr = ((n - (mek << i)) / (mek << (i + mek))) % 2;
			break;
		}
	}
}

int main()
{
	cin >> n;
	++n;
	while ((mek << l) != n)
	{
		++l;
	}
	/////////////////////
	int q;
	cin >> q;
	while (q--)
	{
		cin >> n;
		scanf("%s", a);
		/////////
		int nn = strlen(a);
		for (int i = 0; i < nn; i++)
		{
			stg();
			if (a[i] == 'L')
			{
				if (m == 0)
					continue;
				--m;
				n -= (mek << m);
			}
			else if (a[i] == 'R')
			{
				if (m == 0)
					continue;
				--m;
				n += (mek << m);
			}
			else
			{
				if (m == l - mek)
					continue;
				if (!lr)
					n += (mek << m);
				else
					n -= (mek << m);
				++m;
			}
		}
		cout << n << endl;
	}
	return 0;
}