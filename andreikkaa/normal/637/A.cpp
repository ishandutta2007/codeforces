#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
int cnt[1000007];
int last[1000007];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
		last[x] = i;
	}
	int anspos = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (cnt[i] > cnt[anspos] || (cnt[i] == cnt[anspos] && last[i] < last[anspos]))
		{
			anspos = i;
		}
	}
	printf("%d\n", anspos);
}