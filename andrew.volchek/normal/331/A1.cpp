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


int a[3000005];
ll sums[3000005];
const ll inf = 10000000000000000;
map < int , int > mm;

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);
	sums[0] = 0;
	for (int i = 0; i < n; i++)
	{
		sums[i+1] = sums[i];
		if (a[i] > 0)
			sums[i+1] += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		mm[a[i]] = max(mm[a[i]], i);
	}
	ll ans_eff = -inf;
	int ans_ind = 0;
	for (int i = 0; i < n; i++)
	{
		int r = mm[a[i]];
		if (r != i)
		{
			ll curr = a[i] * 2;
			curr = curr + sums[r] - sums[i+1];
			if (curr > ans_eff)
			{
				ans_eff = curr;
				ans_ind = i;
			}
		}
	}
	
	vector < int > ansd;
	for (int i = 0; i < ans_ind; i++)
	{
		ansd.pb(i+1);
	}
	int r = mm[a[ans_ind]];
	for (int i = ans_ind+1; i < r; i++)
	{
		if (a[i] < 0)
			ansd.pb(i+1);
	}
	for (int i = r+1; i < n; i++)
	{
		ansd.pb(i+1);
	}
	
	cout << ans_eff << " " << ansd.size() << endl;;
	for (int i = 0; i < ansd.size(); i++)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", ansd[i]);
	}
	
	return 0;
}