#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <cstdlib>
#include <time.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define y0 asdfasdf
#define y1 fdsafdsa



int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);
	
	
	int n = 2000;
	cout << n << "\n";
	for (int i = 1; i <= n / 2; i++)
		cout << i << " " << 1 << " " << i << " " << 2 << "\n";
	for (int i = n / 2; i >= 1; i--)
		cout << i << " " << 1 << " " << i << " " << 2 << "\n";
	
	//cerr << clock() * 1. / CLOCKS_PER_SEC << "\n";//  - curtime << "\n";
	return 0;
}