#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define int long long
int n;
int second;
int query(int type, int a, int b, int c)
{
	printf("%lld %lld %lld %lld\n", type, a, b, c);
	fflush(stdout);
	int res;
	scanf("%lld", &res);
	return res;
}
int area[100010];
vector<int> v;
#undef int
int main()
{
	#define int long long
	scanf("%lld", &n);
	second = 2;
	for (int i = 3; i <= n; i++)
	{
		int res = query(2, 1, second, i);
		if (res < 0) second = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if (i != second)
		{
			v.push_back(i);
			area[i] = query(1, 1, second, i);
		}
	}
	sort(v.begin(), v.end(), [](const int &a, const int &b) { return area[a] < area[b]; });
	vector<int> front, back;
	int biggest = v[(int)v.size()-1];
	for (auto a : v)
	{
		if (a != biggest)
		{
			if (query(2, 1, biggest, a) < 0) front.push_back(a);
			else back.push_back(a);
		}
	}
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(second);
	for (auto a : front) ans.push_back(a);
	reverse(back.begin(), back.end());
	ans.push_back(biggest);
	for (auto a : back) ans.push_back(a);
	printf("%lld ", 0ll);
	for (auto a : ans) printf("%lld ", a);
	printf("\n");
  	fflush(stdout);
}