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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a;
	scanf("%d %d", &n, &a);
	int pos = -1;
	if (a % 2 == 1)
	{
		pos = (a + 1) / 2;
	}
	else
	{
		pos = (n - a) / 2 + 1;
	}	
	printf("%d\n", pos);
}