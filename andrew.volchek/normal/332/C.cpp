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

pair < pair < int , int > , int > a[100005];
pair < pair < int , int > , int > b[100005];
int rev[100005];
int was[100005];

bool comp1(const pair < pair < int , int > , int > &p1, const pair < pair < int, int >, int > &p2)
{
	return (p1.fst.snd < p2.fst.snd) || ((p1.fst.snd == p2.fst.snd) && (p1.fst.fst > p2.fst.fst));
}



int main(int argc, char **argv)
{
	int n, p, k;
	cin >> n >> p >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].fst.fst, &a[i].fst.snd);
		a[i].snd = i;
	}
		
	sort(a, a+n, comp1);
	for (int i = 0; i < n; i++)
		rev[a[i].snd] = i;
	for (int i = p-k; i < n; i++)
	{
		b[i - p + k] = a[i];
	}
	sort(b, b + n - p + k);
	vector < int > ans;
	
	int mm = 1000000;
	int mm2 = 1000000;
	int mm3 = 1000000;
	
	for (int i = (n - p + k) - 1; i >= 0; i--)
	{
		if (ans.size() == k)
			break;
		ans.pb(b[i].snd);
		mm = min(rev[b[i].snd], mm);
		mm2 = min(mm2, b[i].fst.snd);
		
	}
	
	//sort(a, a + mm);
	
	for (int i = mm-1; i >= 0; i--)
	{
		if (ans.size() == p)
			break;
		if (a[i].fst.snd == mm2)
			continue;
		was[i] = true;
		ans.pb(a[i].snd);
	}
	
	for (int i = mm-1; i >= 0; i--)
	{
		if (ans.size() == p)
			break;
		if (was[i])
			continue;
		was[i] = true;
		ans.pb(a[i].snd);
	}
	
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]+1);
	}
	
	return 0;
}