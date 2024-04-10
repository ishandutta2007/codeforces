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

const int maxn = 1005;
int a[maxn];
int n;

void rev(int l, int r)
{
	while (l < r)
	{
		swap(a[l], a[r]);
		l++;
		r--;
	}
}

bool check()
{
	for (int i = 0; i < n; i++)
		if (a[i] != i+1)
			return false;
			
	return true;
}


vector < int > used;
vector < pair < int , int > > ans;
vector < int > vv[3];
vector < int > vv2[3];

void rec(int lev)
{
	if (check())
	{
		cout << ans.size() << endl;
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].fst << " " << ans[i].snd << endl;
		exit(0);
	}
	
	if (lev == 3)
		return;
		
	vv2[lev].clear();
	vv2[lev].pb(0);
	
	
	for (int i = 1; i < n-1; i++)
	{
		if (a[i] - a[i-1] != a[i+1] - a[i])
		{
				vv2[lev].pb(i);
				continue;
	}
		if (abs(a[i-1] - a[i]) != 1)
			vv2[lev].pb(i);
			
	}
	vv2[lev].pb(n-1);

	
			
	for (int l = (int)vv2[lev].size() - 1; l >= 0; l--)
	{
		for (int r = l + 1; r < vv2[lev].size(); r++)
		{
			rev(vv2[lev][l], vv2[lev][r]);
			ans.pb(mp(vv2[lev][l]+1, vv2[lev][r]+1));
			rec(lev+1);
			ans.pop_back();
			rev(vv2[lev][l], vv2[lev][r]);
		}
	}
}


int main(int argc, char **argv)
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	
	
	rec(0);
	
	
	return 0;
}