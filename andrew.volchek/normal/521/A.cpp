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

const int maxn = 100005;
const ll mod = 1000000007;

char s[maxn];
int cnt[26];


int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d\n", &n);
	scanf("%s", s);
	
	
	for (int i = 0; i < n; i++)
		cnt[s[i] - 'A']++;
		
	int m = 0;
	
	for (int i = 0; i < 26; i++)
		m = max(m, cnt[i]);
		
	int x = 0;
	for (int i = 0; i < 26; i++)
		x += cnt[i] == m;
		
	ll ans = 1;
	
	for (int i = 0; i < n; i++)
		ans = (ans * x) % mod;
		
	cout << ans << endl;
	
	return 0;
}