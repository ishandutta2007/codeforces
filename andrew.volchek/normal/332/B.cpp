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
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

int a[200005];
ll sums[200005];
ll mm[200005];


int main(int argc, char **argv)
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	sums[0] = 0;
	for (int i = 0; i < n; i++)
		sums[i+1] = sums[i] + a[i];
		
	for (int i = n - k; i >= 0; i--)
	{
		mm[i] = sums[i + k] - sums[i];
		if ( i != (n-k))
			mm[i] = max(mm[i], mm[i+1]);
	}
	
	int aind = 0;
	ll amax = 0;
	for (int i = 0; i < n - 2*k + 1; i++)
	{
		
		ll curr = sums[i+k] - sums[i];
		//cout << i << " " << curr <<endl;
		curr += mm[i+k];
		if (curr > amax)
		{
			amax = curr;
			aind = i;
		}
	}
	
	int bind = 0;
	ll bmax = 0;
	for (int i = aind + k; i <= n-k; i++)
	{
		ll curr = sums[i + k] - sums[i];
		if (curr > bmax)
		{
			bmax = curr;
			bind = i;
		}
	}
	
	cout << aind +1 << " " << bind+1;
	
	return 0;
}