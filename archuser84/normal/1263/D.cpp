#include <iostream>
#include <string.h>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;

bool visited[26] = { 0 };
bool exist[26] = { 0 };
bool a[26][26] = { 0 };

void bfs(int start)
{
	int queue[26];
	int qstart = 0;
	int qend = 1;
	queue[0] = start;
	visited[start] = 1;
	while (qend - qstart > 0)
	{
		int c = queue[qstart];
		for (int i = 0; i < 26; i++)
		{
			if (a[c][i] && !visited[i])
			{
				queue[qend++] = i;
				visited[i] = 1;
			}
		}
		++qstart;
	}
}

int main()
{
	int n;
	cin >> n;
	for (LoopN)
	{
		char s[100];
		cin >> s;
		int size = strlen(s);
		for (int j = 0; j < size - 1; j++)
		{
			a[s[j] - 'a'][s[j + 1] - 'a'] = true;
			a[s[j + 1] - 'a'][s[j] - 'a'] = true;
			exist[s[j] - 'a'] = true;
		}
		exist[s[size - 1] - 'a'] = true;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		if (!visited[i] && exist[i])
		{
			++ans;
			bfs(i);
		}
	}
	cout << ans << '\n';
}