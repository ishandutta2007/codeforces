#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <vector>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define y1 asdkjghjasd
#define fst first
#define snd second
#define y0 sakjglajaa
#define ll long long
#define ull unsigned long long
#define ld long double

map < string, int > dp;

string tolower(const string &x)
{
	string res;
	for (char ch : x)
		res += tolower(ch);
	return res;
}

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	dp["polycarp"] = 1;
	
	for (int i = 0; i < n; i++)
	{
		string a, b, c;
		cin >> a >> b >> c;
		dp[tolower(a)] = dp[tolower(c)] + 1;
	}
	
	int ans = 0;
	for (auto kv : dp)
		ans = max(ans, kv.snd);
		
	cout << ans << endl;	
	
	return 0;
}