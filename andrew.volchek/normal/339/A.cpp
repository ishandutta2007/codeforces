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
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

int a[105];

int main(int argc, char **argv)
{
	int cnt = 0;
	while (scanf("%d", &a[cnt++]) >= 0)
	{
		char ch;
		if (scanf("%c", &ch) < 0)
			break;
		if (ch == '\n')
			break;
	}
	
	sort(a, a+cnt);
	
	for (int i = 0; i < cnt; i++)
	{
		if (i)
			cout << '+';
		cout << a[i];
	}
	
	return 0;
}