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
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}


int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	string name[2];
	cin >> name[0] >> name[1];
	
	int n;
	cin >> n;
	map < pair < int, int >, int > m;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		int x;
		char type;
		int y;
		char card;
		scanf("%d %c %d %c\n", &x, &type, &y, &card);
		int t = (type == 'a') ? 1 : 0;
		
		if (card == 'r')
		{
			if (m[mp(t, y)] < 2)
			{
				cout << name[t] << " " << y << " " << x << endl;
			}
			m[mp(t, y)] = 10;
		}
		else
		{
			if (m[mp(t, y)] == 1)
			{
				cout << name[t] << " " << y << " " << x << endl;
			}
			m[mp(t, y)]++;
		}
	}
	

	return 0;
}