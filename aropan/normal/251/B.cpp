#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

vector <int> p, q, s;

vector <int> inv(vector <int> p)
{
	vector <int> res;
	res.resize(p.size());
	for (int i = 0; i < (int)p.size(); i++)
		res[q[i]] = p[i];
	return res;
}

vector <int> per(vector <int> p)
{
	vector <int> res;
	res.resize(p.size());
	for (int i = 0; i < (int)p.size(); i++)
		res[i] = p[q[i]];
	return res;
}

int n, k;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	scanf("%d %d", &n, &k);
	q.resize(n);
	s.resize(n);
	p.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &q[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	
	for (int i = 0; i < n; i++)
	{
		q[i]--;
		s[i]--;
	}
	
	for (int i = 0; i < n; i++)
		p[i] = i;
		
	if (p == s)
	{
		puts("NO");
		return 0;
	}
	
	
	bool finv = inv(p) != s;
	bool fper = per(p) != s;

	for (int i = 1; i <= k; i++)
	{
		p = per(p);
		if (p == s)
		{
			if (((k - i) % 2 == 0) && (i == k || i > 1 || finv))
			{
				puts("YES");
				return 0;
			}
			break;
		}
	}

	for (int i = 0; i < n; i++)
		p[i] = i;
		
	for (int i = 1; i <= k; i++)
	{
		p = inv(p);
		if (p == s)
		{
			if (((k - i) % 2 == 0) && (i == k || i > 1 || fper))
			{
				puts("YES");
				return 0;
			}
			break;
		}
	}
	puts("NO");
	return 0;
}