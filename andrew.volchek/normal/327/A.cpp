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

int a[111];
int n;

int main(int argc, char **argv)
{
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		//ans += (a[i] == 1);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			for (int h = i; h <= j; h++)
				a[h] = 1 - a[h];
			
			int curr = 0;
			
			for (int h = 0; h < n; h++)
				curr += (a[h] == 1);
				
			ans = max(ans, curr);
			
			for (int h = i; h <= j; h++)
				a[h] = 1 - a[h];
		}
	}
	
	cout << ans;
	
	return 0;
}