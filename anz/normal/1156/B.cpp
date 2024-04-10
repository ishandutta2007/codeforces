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
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		for (; b; a %= b, swap(a, b));
		return a;
	}
	return a;
}

int albet[26];
bool hasAnswer = false;
string ans;
int cache[26];
int cnt = 0;

void dfs(int n, int start, string s)
{
	if (hasAnswer) return;
	if (cnt == n)
	{
		ans = s;
		hasAnswer = true;
		return;
	}
	cache[start] = 1;
	for (int i = 0; i < 26; i++)
	{
		if (hasAnswer) return;
		if (albet[i] && cache[i] == 0 && i+1 != start && i-1 != start)
		{
			dfs(n+1, i, s + (char)('a' + i));
		}
	}
	cache[start] = 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(albet, 0, sizeof(albet));
		memset(cache, 0, sizeof(cache));
		hasAnswer = false;
		cnt = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
			albet[s[i] - 'a']++;

		for (int i = 0; i < 26; i++)
			if (albet[i]) cnt++;

		for (int i = 0; i < 26; i++)
		{
			if (hasAnswer) break;
			if (!albet[i]) continue;
			string tmp;
			tmp += (char)('a' + i);
			
			dfs(1, i, tmp);	
		}

		if (hasAnswer)
		{
			for (int i = 0; i < ans.size(); i++)
			{
				for (int j = 0; j < albet[ans[i]-'a']; j++)
					printf("%c", ans[i]);
			}
		}
		else printf("No answer");
		printf("\n");
	}
}