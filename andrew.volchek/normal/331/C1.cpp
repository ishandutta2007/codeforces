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
	int ans = 0;
	while (n)
	{
		int mm = 0;
		int nn = n;
		while (nn)
		{
			mm = max(mm, nn % 10);
			nn /= 10;
		}
		n -= mm;
		ans++;
	}
	cout << ans;
	
	return 0;
}