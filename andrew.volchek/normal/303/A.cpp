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
	int n; 
	cin >> n;
	if (!(n&1))
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		int t = n - i - 1;
		if (t < i)
			cout << n - i + t;
		else
			cout << t - i;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " ";
		cout << n - i - 1;
	}
	return 0;
}