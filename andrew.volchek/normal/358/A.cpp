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
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull long long
#define fst first
#define snd second
#define ld long double

int a[1005];

int main()
{
	int n;
	cin >> n;
	if (n <= 2)
	{
		cout << "no" << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n-1; j++)
		{
			int mi1 = min(a[i], a[i+1]);
			int ma1 = max(a[i], a[i+1]);
			int mi2 = min(a[j], a[j+1]);
			int ma2 = max(a[j], a[j+1]);


			if (((mi1 <= mi2) && (mi2 <= ma1) && (mi1 <= ma2) && (ma2 <= ma1)) ||
				((mi2 <= mi1) && (mi1 <= ma2) && (mi2 <= ma1) && (ma1 <= ma2)) ||
				((mi1 <= mi2) && (ma1 <= mi2)) || ((ma2 <= mi1) && (ma2 <= ma1)) ||
				((mi2 <= mi1) && (ma2 <= mi1)) || ((ma1 <= mi2) && (ma1 <= ma2)))
			{
			}
			else
			{
				cout << "yes" << endl;
				return 0;
			}
		}
	}

	cout << "no" << endl;
	//cin >> n;
	
	return 0;
}