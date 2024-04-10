#include <bits/stdc++.h>
using namespace std;
int n, bs = 0;
inline int Query(string &s, int num)
{
	printf("%s\n", s.c_str());
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return (num + x - bs) >> 1;
}
inline int Query(int a)
{
	string s;
	for(int i = 1; i <= n; i++)
		s += (i != a) ? 'F' : 'T';
	return Query(s, 1);
}
inline int Query(int a, int b)
{
	string s;
	for(int i = 1; i <= n; i++)
		s += (i != a && i != b) ? 'F' : 'T';
	return Query(s, 2);
}
inline int Query(int a, int b, int c)
{
	string s;
	for(int i = 1; i <= n; i++)
		s += (i != a && i != b && i != c) ? 'F' : 'T';
	return Query(s, 3);
}
inline int Query(int a, int b, int c, int d)
{
	string s;
	for(int i = 1; i <= n; i++)
		s += (i != a && i != b && i != c && i != d) ? 'F' : 'T';
	return Query(s, 4);
}
inline void Init()
{
	string s;
	for(int i = 1; i <= n; i++)
		s += 'F';
	printf("%s\n", s.c_str());
	fflush(stdout);
	scanf("%d", &bs);
}
int ans[1010];
inline void Work(vector<int> a, int r)
{
	int m = a.size();
	vector<int> vec;
	for(int i = 0; i < m; i += 4)
	{
		if(i + 3 >= m)
		{
			for(int j = 0; i + j < m; j++)
				ans[a[i + j]] = Query(a[i + j]);
		}
		else
		{
			int tot = Query(a[i], a[i + 1], a[i + 2], a[i + 3]);
			if(tot == 0)
				ans[a[i]] = ans[a[i + 1]] = ans[a[i + 2]] = ans[a[i + 3]] = 0;
			else if(tot == 4)
				ans[a[i]] = ans[a[i + 1]] = ans[a[i + 2]] = ans[a[i + 3]] = 1;
			else if(tot == 1)
			{
				int t2 = Query(a[i], a[i + 1]);
				if(t2 == 1)
					ans[a[i + 2]] = ans[a[i + 3]] = 0, ans[a[i + 1]] = (r << 1 | 1) * 10000 + i, vec.push_back(a[i]);
				else
					ans[a[i]] = ans[a[i + 1]] = 0, ans[a[i + 3]] = (r << 1 | 1) * 10000 + i + 2, vec.push_back(a[i + 2]);
			}
			else if(tot == 3)
			{
				int t2 = Query(a[i], a[i + 1]);
				if(t2 == 1)
					ans[a[i + 2]] = ans[a[i + 3]] = 1, ans[a[i + 1]] = (r << 1 | 1) * 10000 + i, vec.push_back(a[i]);
				else
					ans[a[i]] = ans[a[i + 1]] = 1, ans[a[i + 3]] = (r << 1 | 1) * 10000 + i + 2, vec.push_back(a[i + 2]);
			}
			else
			{
				int t2 = Query(a[i], a[i + 1]);
				if(t2 == 0)
					ans[a[i]] = ans[a[i + 1]] = 0, ans[a[i + 2]] = ans[a[i + 3]] = 1;
				else if(t2 == 2)
					ans[a[i]] = ans[a[i + 1]] = 1, ans[a[i + 2]] = ans[a[i + 3]] = 0;
				else
				{
					int t3 = Query(a[i], a[i + 2]);
					if(t3 == 0)
						ans[a[i]] = ans[a[i + 2]] = 0, ans[a[i + 1]] = ans[a[i + 3]] = 1;
					else if(t3 == 2)
						ans[a[i]] = ans[a[i + 2]] = 1, ans[a[i + 1]] = ans[a[i + 3]] = 0;
					else
						ans[a[i + 1]] = (r << 1 | 1) * 10000 + i, ans[a[i + 2]] = (r << 1 | 1) * 10000 + i, ans[a[i + 3]] = (r << 1) * 10000 + i, vec.push_back(a[i]);
				}
			}
		}
	}
	if(vec.size())
	{
		Work(vec, r + 1);
		for(int i = 0; i < m; i++)
			if(ans[a[i]] >= (r << 1) * 10000 && ans[a[i]] <= ((r + 1) << 1) * 10000)
			{
				if(ans[a[i]] < (r << 1 | 1) * 10000)
					ans[a[i]] = ans[a[ ans[a[i]] % 10000 ]];
				else
					ans[a[i]] = !ans[a[ ans[a[i]] % 10000 ]];
			}
	}
}
int main()
{
	srand(20060223);
	scanf("%d", &n);
	Init();
	vector<int> a;
	for(int i = 1; i <= n; i++)
		a.push_back(i);
	random_shuffle(a.begin(), a.end());
	Work(a, 1);
	for(int i = 1; i <= n; i++)
		printf("%c", "FT"[ans[i]]);
	putchar('\n');
	fflush(stdout);
	scanf("%d", &n);
	return 0;
}