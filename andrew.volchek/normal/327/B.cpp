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

int p[2000005];

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	
	for (int i = 2; i*i <= 2000000; i++)
	{
		if (!p[i])
		{
			for (int j = i*i; j <= 2000000; j += i)
				p[j] = 1;
		}
	}
	
	int curr = 2;
	int cnt = 0;
	
	while (cnt < n)
	{
		while (p[curr]) curr++;
		if (cnt)
			printf(" ");
		printf("%d", curr);
		curr++;
		cnt++;
	}
	
	
	
	return 0;
}