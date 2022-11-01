#include<bits/stdc++.h>
using namespace std;

const int N = 55;
const char * tar = "abacaba";

int n;
char str[N], tmp[N];

bool work(int p)
{
	for (int i = 0; i < 7; i++)
		if (tmp[p + i] != tar[i]) return 0;
	return 1;
}

bool check(int p)
{
	for (int i = 0; i < 7; i++)
		if (str[p + i] != tar[i] && str[p + i] != '?') return 0;
	for (int i = 1; i <= n; i++) tmp[i] = str[i];
	for (int i = 0; i < 7; i++)
		if (str[p + i] == '?') tmp[p + i] = tar[i];
	for (int i = 1; i + 6 <= n; i++)
		if (i != p && work(i)) return 0;
	puts("Yes");
	for (int i = 1; i <= n; i++)
		putchar(tmp[i] == '?' ? 'd' : tmp[i]);
	puts("");
	return 1;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", str + 1);
		bool ans = 0;
		for (int i = 1; i + 6 <= n; i++) if (check(i)) {ans = 1; break;}
		if (!ans) puts("No");
	}
	return 0;
}