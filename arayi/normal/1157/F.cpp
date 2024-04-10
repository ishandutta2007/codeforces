#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
using lli = long long int;
using namespace std;
const int N = 200010;
const int mod = 1e9 + 7;
int n;
int a[N];
int pat, ind1, ind2, i1, i2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		a[d]++;
	}
	int sm = 0;
	int i = 0;
	while (i < N)
	{
		
		if (a[i])
		{
			sm = a[i];
			i1 = i;
			i++;
			while (i < N - 1 && a[i] > 1)
			{
				sm += a[i];
				i++;
			}
			sm += a[i];
			if (sm > pat)
			{
				ind1 = i1;
				ind2 = i;
				pat = sm;
			}
			if(a[i]) i--;
		}
		i++;

	}
	
	cout << pat << endl;
	for (int i = ind1; i <= ind2; i++)
	{
		while (a[i] > 1)
		{
			cout << i << " ";
			a[i]--;
		}
	}
	for (int i = ind2; i >= ind1; i--)
	{
		if(a[i])
			cout << i << " ";
	}
	return 0;
}