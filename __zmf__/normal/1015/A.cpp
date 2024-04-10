#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		if(ch == '-') nega = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		sum = sum * 10 + ch - '0'; ch = getchar();
	}
	return sum * nega;
}
const int N = 1e5 + 9;
int n, m, ans;
bool vis[N];
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		int l = read(), r = read();
		for (int j = l; j <= r; j++) vis[j] = 1;
	}
	for (int i = 1; i <= m; i++) ans = ans + (!vis[i]);
	cout << ans << endl;
	for (int i = 1; i <= m; i++)
		if(!vis[i]) cout << i << " ";
	return 0;
}