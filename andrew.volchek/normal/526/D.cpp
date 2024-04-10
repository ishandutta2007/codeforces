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
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 1000005;

char s[maxn];
int z[maxn];
int ans[maxn];
int ans2[maxn];

int main()
{
	//srand(time(NULL));
	//gen();
	//	freopen("a.in", "r", stdin);
	
	int n, k;
	scanf("%d %d\n", &n, &k);
	
	
//	for (int i = 0; i < n; i++)
	//	s[i] = 1;
	
	scanf("%s", s);
	
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	
	if (k == 1)
		ans[0] = 1;
	
	for (int i = 1; i < n; i++)
	{
		if ((i + 1) % k)
			continue;
			
		int ab = (i + 1) / k;
		
		
		bool good = true;
		
		
		int j = i;
		int c = k;
		
		while (c > 1)
		{
			if (c & 1)
			{
				good &= z[j - ab + 1] >= ab;
				j -= ab;
				c--;
			}
			else
			{
				good &= z[j - ab * (c / 2) + 1] >= (ab * (c / 2));
				j -= ab * (c / 2);
				c >>= 1;
			}
			//c >>= 1;
		}
		
		if (!good)
			continue;
			
		//if (i == 17)
		//	cerr << pr[i] << endl;
			
		ans[i] = 1;
		
		if (i + 1 < n && z[i + 1])
		{
			int r = min(min(n - 1, i + ab), i + 1 + z[i + 1] - 1);
			ans2[i + 1]++;
			ans2[r + 1]--;
		}
	}
	
	int v = 0;
	for (int i = 0; i < n; i++)
	{
		v += ans2[i];
		ans[i] |= bool(v);
	}
	
	for (int i = 0; i < n; i++)
		printf("%d", ans[i]);
	printf("\n");
	

	return 0;
}