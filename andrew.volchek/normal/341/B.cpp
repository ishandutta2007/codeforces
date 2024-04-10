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

int arr[100005];
int tree[100005];
const int inf = 1000000000;
int n; 


void add(int i, int val)
{
	while (i < n+1)
	{
		tree[i] = max(tree[i], val);
		i = (i + 1) | i;
	}
}

int get(int r)
{
	int res = 0;
	while (r >= 0)
	{
		res = max(res, tree[r]);
		r = ((r + 1) & r) - 1;
	}
	return res;
}

int main(int argc, char **argv)
{
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
		
	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		int res = get(arr[i]) + 1;
		ans = max(res, ans);
		add(arr[i], res);
	}
	
	cout << ans;
	
	return 0;
}