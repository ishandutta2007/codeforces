#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	int n = 0;
	char num[10];
	gets(num);
	for (int i = 0; num[i]; i++)
	{
		n *= 10;
		n += num[i] - '0';
	}
	char s[100001];
	gets(s);
	int eight = 0;
	for (int i = 0; i < n - 10; i++)
	{
		if (s[i] == '8') eight++;
	}

	if (eight > (n - 11) / 2) puts("YES");
	else puts("NO");
}