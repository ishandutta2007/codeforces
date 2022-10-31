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


int a[4][30];

int main()
{
	//freopen("a.in", "r", stdin);
	int k;
	cin >> k;
	
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 2 && i != 0)
				continue;
			if (k)
			{
				a[j][i] = 1;
				k--;
			}
		}
	}
	
	/*
	 +------------------------+
|O.O.O.O.O.O.O.#.#.#.#.|D|)
|O.O.O.O.O.O.#.#.#.#.#.|.|
|O.......................|
|O.O.O.O.O.O.#.#.#.#.#.|.|)
+------------------------+*/
	
	cout << "+------------------------+" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "|";
		for (int j = 0; j < 11; j++)
		{
			if (j && i == 2)
			{
				cout << "..";
				continue;
			}
			if (a[i][j])
				cout << "O.";
			else
				cout << "#.";
		}
		
		if (i == 0)
			cout << "|D|)" << endl;
		else if (i == 1)
			cout << "|.|" << endl;
		else if (i == 2)
			cout << "..|" << endl;
		else
			cout << "|.|)" << endl;
	}
	
	cout << "+------------------------+" << endl;
	
	return 0;
}