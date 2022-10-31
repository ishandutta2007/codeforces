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

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

ld dp[1005][1005][2];

ld rec_dracon(int b, int w);

ld rec_princess(int b, int w)
{	
	if (!(w + b))
		return 0.0;
	
	if (!w)
		return 0.0;
		
	if (!b)
		return 1.0;
		
	if (dp[b][w][0] > -1.0)
		return dp[b][w][0];
		
	ld prw = (ld)w / (b + w);
	ld ans = prw + (1.0 - rec_dracon(b-1, w)) * (1.0 - prw);
	
	return dp[b][w][0] = ans;
}

ld rec_dracon(int b, int w)
{
	if (!(w + b))
		return 1.0;
	
	if (!w)
		return 1.0;
	if (!b)
		return 1.0;
	
	if (dp[b][w][1] > -1.0)
		return dp[b][w][1];
		
	ld prw = (ld)w / (b + w);
	ld ans = prw;
	
	
	if (w)
		ans += (1.0 - prw) * (1.0 - rec_princess(b-1, w-1)) * ((ld)w / (b + w - 1));
	if (b-1)
		ans += (1.0 - prw) * (1.0 - rec_princess(b-2, w)) * ((ld)(b-1) / (w + b - 1));
		
	return dp[b][w][1] = ans;
}

int main(int argc, char **argv)
{
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			dp[i][j][0] = dp[i][j][1] = -2.0;
	
	int b, w;
	cin >> w >> b;
	cout.precision(10);
	cout << fixed << rec_princess(b, w);
	return 0;
}