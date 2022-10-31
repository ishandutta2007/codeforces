#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

ll a[16] = {
	8848,
	958,
	12766,
	6695,
	1100,
	807,
	31962,
	146,
	20,
	25,
	134,
	10000,
	663268,
	154103,
	1642,
	106,
};


int main()
{
	//freopen("a.in", "r", stdin);
	
	//cout << (int)']' << endl;
	//return 0;
	char str1[30], str2[30];
	cin.getline(str1, 100); 
	cin.getline(str2, 100); 
	

	assert((strlen(str1) & 1) == 0);

	int res1 = 0;
	int res2 = 0;
	for (int i = 0; i < strlen(str1); i+=2)
	{
		if (str1[i] == '[')
		{
			if (str2[i] == '8')
			{
				res1--;
			}
			else if (str2[i] == '(')
				res1++;
		}
		else if (str1[i] == '(')
		{
			if (str2[i] == '8')
				res1++;
			else if (str2[i] == '[')
				res1--;
		}
		else
		{
			if (str2[i] == '(')
				res1--;
			else if (str2[i] == '[')
				res1++;
			
		}
	}
	if (res1 > 0)
	{
		puts("TEAM 1 WINS");
	}
	else if (res1 == 0)
	{
		puts("TIE");
	}
	else
	{
		puts("TEAM 2 WINS");
	}
	

	return 0;
}