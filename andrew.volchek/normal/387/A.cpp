#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}


int main()
{
	int hs, ms;
	scanf("%d:%d\n", &hs, &ms);
	int ht, mt;
	scanf("%d:%d", &ht, &mt);
	int t1 = hs * 60 + ms;
	int t2 = ht * 60 + mt;
	t1 -= t2;
	
	if (t1 < 0)
		t1 += 24 * 60;
		
	printf("%02d:%02d", t1 /  60, t1 % 60);
	
	//freopen("a.in", "r", stdin);
	
	return 0;
}