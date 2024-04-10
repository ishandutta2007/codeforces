#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int q, mekqan, erkuqan, zroqan;
string a;

int main()
{
	cin >> q >> a;
	for (int i = 0; i < q; i++)
	{
		if (a[i] == '1')
		{
			mekqan++;
		}
		else if (a[i] == '2')
		{
			erkuqan++;
		}
		else
			zroqan++;
	}
	q /= 3;
	mekqan -= q;
	zroqan -= q;
	erkuqan -= q;
	if (zroqan<0)
	{
		for (int i = 0; i < a.length() && zroqan; i++)
		{
			if (a[i] == '1' && mekqan > 0)
			{
				a[i] = '0';
				zroqan++;
				mekqan--;
			}
			else if (a[i] == '2'&& erkuqan > 0)
			{
				a[i] = '0';
				zroqan++;
				erkuqan--;
			}
		}
	}
	if (erkuqan<0)
	{
		for (int i = a.length() - 1; i >= 0 && erkuqan; i--)
		{
			if (a[i] == '1'&& mekqan > 0)
			{
				a[i] = '2';
				erkuqan++;
				mekqan--;
			}
			else if (a[i] == '0'&& zroqan > 0)
			{
				a[i] = '2';
				erkuqan++;
				zroqan--;
			}
		}
	}
	if (zroqan)
	{
		for (int i = a.length() - 1; i >= 0 && zroqan; i--)
		{
			if (a[i] == '0')
			{
				a[i] = '1';
				zroqan--;
				mekqan++;
			}
		}
	}
	if (erkuqan)
	{
		for (int i = 0; i < a.length() && erkuqan; i++)
		{
			if (a[i] == '2')
			{
				a[i] = '1';
				erkuqan--;
				mekqan++;
			}
		}
	}
	cout << a;
	return 0;
}