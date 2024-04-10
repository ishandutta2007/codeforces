#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int maxs = 27;

int f[maxs] , g[maxs] , a[maxn] , b[maxn] , s[maxn] , n;

char S[maxn] , A[maxn] , B[maxn];

void print(int k)
{
	int pt = 0;
	for(int i = 0; i < k; i++)
		if(g[i] == -1)
		{
			while(f[pt] != -1)
				pt++;
			g[i] = pt;
			f[pt] = i;
		}

	for(int i = 0; i < n; i++)
		s[i] = f[s[i]];

	bool res = 1;
	for(int i = 0; i < n; i++)
		if(s[i] != a[i])
		{
			res &= (s[i] > a[i]);
			break;
		}

	for(int i = 0; i < n; i++)
		if(s[i] != b[i])
		{
			res &= (s[i] < b[i]);
			break;
		}

	for(int i = 0; i < k; i++)
		if(f[g[i]] != i)
			cout << 1/0;

	if(!res)
		cout << 1/0;

	printf("YES\n");
	for(int i = 0; i < k; i++)
		printf("%c", (char)(f[i] + 'a'));
	printf("\n");
}

int solve()
{
	memset(f , -1 , sizeof f);
	memset(g , -1 , sizeof g);

	int k;
	scanf("%d", &k);

	scanf("%s%s%s", S, A, B);
	n = strlen(S);

	for(int i = 0; i < n; i++)
	{
		a[i] = A[i] - 'a';
		b[i] = B[i] - 'a';
		s[i] = S[i] - 'a';
	}

	int lcp = 0;
	while(lcp < n && a[lcp] == b[lcp])
	{
		if(f[s[lcp]] != -1 && f[s[lcp]] != a[lcp])
			return printf("NO\n");
		if(g[a[lcp]] != -1 && g[a[lcp]] != s[lcp])
			return printf("NO\n");

		f[s[lcp]] = a[lcp];
		g[a[lcp]] = s[lcp];
		lcp++;
	}
	if(lcp == n)
	{
		print(k);
		return 0;
	}

	bool shit = 1;
	for(int i = lcp; i < n; i++)
	{
		for(int j = a[i] + 1; j < ((i == lcp)? b[i] : k); j++)
		{
			bool res = 1;
			if(f[s[i]] != -1 && f[s[i]] != j)
				res = 0;
			if(g[j] != -1 && g[j] != s[i])
				res = 0;

			if(res)
			{
				f[s[i]] = j;
				g[j] = s[i];
				print(k);
				return 0;
			}
		}

		if(f[s[i]] != -1 && f[s[i]] != a[i])
		{
			shit = 0;
			break;
		}
		if(g[a[i]] != -1 && g[a[i]] != s[i])
		{
			shit = 0;
			break;
		}

		f[s[i]] = a[i];
		g[a[i]] = s[i];
	}

	if(shit)
	{
		print(k);
		return 0;
	}

	memset(f , -1 , sizeof f);
	memset(g , -1 , sizeof g);
	for(int i = 0; i < lcp; i++)
		f[s[i]] = a[i] , g[a[i]] = s[i];

	shit = 1;
	for(int i = lcp; i < n; i++)
	{
		for(int j = ((i == lcp)? a[i] + 1 : 0); j < b[i]; j++)
		{
			bool res = 1;
			if(f[s[i]] != -1 && f[s[i]] != j)
				res = 0;
			if(g[j] != -1 && g[j] != s[i])
				res = 0;

			if(res)
			{
				f[s[i]] = j;
				g[j] = s[i];
				print(k);
				return 0;
			}
		}

		if(f[s[i]] != -1 && f[s[i]] != b[i])
		{
			shit = 0;
			break;
		}
		if(g[b[i]] != -1 && g[b[i]] != s[i])
		{
			shit = 0;
			break;
		}

		f[s[i]] = b[i];
		g[b[i]] = s[i];
	}

	if(shit)
	{
		print(k);
		return 0;
	}

	printf("NO\n");
	return 0;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
		solve();
}