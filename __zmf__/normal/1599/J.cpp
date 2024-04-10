/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1509, M = 1509;
int n, a[N], ans[N], w[N];
vector<int> v0, v1;
unordered_map <int, int> mp;
signed main()
{
	srand(time(0));
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n - 1; i++)
		if(a[i] == a[i + 1])
		{
			puts("YES");
			putchar('0');
			for (int j = 1; j <= i; j++) printf(" %d", a[j]);
			for (int j = i + 2; j <= n; j++) printf(" %d", a[j]);
			return 0;
		}
	for (int i = 1; i <= n; i++) 
		if(a[i] & 1) v1.push_back(a[i]);
		else v0.push_back(a[i]);
	if(v0.size() >= 3)
	{
		int sum = v0[0] + v0[1] + v0[2];
		sum /= 2;
		for (int i = 1; i <= 3; i++) ans[i] = sum - v0[i - 1];
		for (int i = 4; i <= v0.size(); i++) ans[i] = v0[i - 1] - ans[1];
		for (int i = 1; i <= v1.size(); i++) ans[i + v0.size()] = v1[i - 1] - ans[1];
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
		return 0;
	}
	if(v0.size() >= 1 && v1.size() >= 2)
	{
		int sum = v0[0] + v1[0] + v1[1], cnt = 0;
		sum /= 2;
		ans[++cnt] = sum - v0[0]; ans[++cnt] = sum - v1[0]; ans[++cnt] = sum - v1[1];
		for (int i = 1; i < v0.size(); i++) ans[++cnt] = v0[i] - ans[1];
		for (int i = 2; i < v1.size(); i++) ans[++cnt] = v1[i] - ans[1];
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
		return 0;
	}
	double tim = 0;
	while(double(tim) / CLOCKS_PER_SEC <= 0.85)
	{
		random_shuffle(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) w[i] = w[i - 1] + a[i];
	//	for (int i = 1; i <= n; i++) cout << a[i] << endl;
		for (int i = 2; i <= n; i++)
		{
			mp.clear();
			for (int j = 1; j + i - 1 <= n; j++)
			{
				if(mp[w[j + i - 1] - w[j - 1]])
				{
					int tmp = mp[w[j + i - 1] - w[j - 1]];
					int cnt = 1;
					ans[1] = 0;
					for (int k = 2; k <= 2 * i; k++)
					{
						int id = k / 2;
						if(k & 1) cnt++, ans[cnt] = a[j + id - 1] - ans[cnt - 1];
						else cnt++, ans[cnt] = a[tmp + id - 1] - ans[cnt - 1];
					}
					for (int k = 1; k <= n; k++)
						if((k < tmp) || (k > j + i - 1) || (k > tmp + i - 1 && k < j)) ans[++cnt] = a[k];
					puts("YES");
					for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
					return 0;
				}
				mp[w[j + i - 1]- w[j - 1]] = j;
			}
		}
		tim = clock();
	//	cout << tim << endl;
	}
	puts("NO");
	return 0;
}