#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second



int main(int argc, char **argv)
{
	ll a, b;
	char str[256];
	cin >> a >> b;
	cin.ignore();
	gets(str);
	
	int len = strlen(str);
	ll ox, oy;
	ll x, y;
	x = 0; 
	y = 0;
	for (int i = 0; i < len; i++)
	{
		switch (str[i])
		{
			case 'R':
				x++;
				break;
			case 'L':
				x--;
				break;
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
		}
	}
	
	ox = x;
	oy = y;
	
	x = 0; 
	y = 0;
	
	//cout << ox << " " << oy;
	
	for (int i = 0; i < len+1; i++)
	{
		ll ax = a - x;
		ll ay = b - y;
		
		if (ax == 0 && ay == 0)
		{
			cout << "Yes";
			return 0;
		}
		
		if (ox != 0 && oy != 0)
		{
			if (((ox > 0 && ax > 0) || (ox < 0 && ax < 0)) && ((oy > 0 && ay > 0) || (oy < 0 && ay < 0)) )
			{
				if ((ax / ox) * ox == ax && (ay / oy) * oy == ay)
				{
					if (ax / ox == ay / oy)
					{
						cout << "Yes";
						return 0;
					}
				}
			}
		}
		else if (ox != 0)
		{
			if (ay == 0)
			{
				if ((ox > 0 && ax > 0) || (ox < 0 && ax < 0))
				{
					if ((ax / ox) * ox == ax)
					{
						cout << "Yes";
						return 0;
					}
				}
			}
		}
		else if (oy != 0)
		{
			//cout << x << " " <<  a << endl;;
			if (ax == 0)
			{
				if ((oy > 0 && ay > 0) || (oy < 0 && ay < 0))
				{
					if ((ay / oy) * oy == ay)
					{
						cout << "Yes";
						return 0;
					}
				}
			}
		}
		
		if (i == len)
			break;
		
		switch (str[i])
		{
			case 'R':
				x++;
				break;
			case 'L':
				x--;
				break;
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
		}
	}
	
	cout << "No";
	return 0;
}