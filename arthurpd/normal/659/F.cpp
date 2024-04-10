//http://codeforces.com/contest/659/problem/F
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

long long val[1123*1123];
long long ans[1123*1123];
long long p[1123456];
long long size[1123456];
bool been[1123456];
long long largest = 1;
long long n, m, k;

long long find(long long a)
{
	if(p[a] == a)
		return a;
	return p[a] = find(p[a]);
}

void join(long long a, long long b)
{
	a = find(a), b = find(b);
	if(a == b)
		return;
	size[b] += size[a];
	p[a] = b;
	if(size[b] > largest)
		largest = size[b];
}

void answer(long long a, long long x)
{
//	printf("%I64d\n", x);
	queue<long long> q;
	q.push(a);
	been[a] = true;
	for(long long i = 0; i < x; i++)
	{
		a = q.front();
		q.pop();
		ans[a] = k / x;
		if(a % m != 0 && been[a-1] == 0 && val[a-1] >= k/x)
		{
			q.push(a-1);
			been[a-1] = true;
		}
		if(a % m != m-1 && been[a+1] == 0 && val[a+1] >= k/x)
		{
			q.push(a+1);
			been[a+1] = true;
		}
		if(a - m >= 0 && been[a-m] == 0 && val[a-m] >= k/x)
		{
			q.push(a-m);
			been[a-m] = true;
		}
		if(a + m < n*m && been[a+m] == 0 && val[a+m] >= k/x)
		{
			q.push(a+m);
			been[a+m] = true;
		}
	}
	for(long long i = 0; i < n; i++, printf("\n"))
		for(long long j = 0; j < m; j++)
			printf("%I64d ", ans[i*m + j]);
}

int main(void)
{
	scanf("%I64d %I64d %I64d", &n, &m, &k);
	vector<pair<long long,long long> > q;
	for(long long i = 0; i < n; i++)
		for(long long j = 0; j < m; j++)
		{
			scanf("%I64d", &val[i*m + j]);
			q.push_back(pair<long long,long long> (val[i*m + j], i*m + j));
		}
	sort(q.rbegin(), q.rend());
	for(long long i = 0; i < q.size(); i++)
	{
		long long x = q[i].second;
		size[x] = 1;
		p[x] = x;
		if(x % m != 0 && size[x-1])
			join(x, x-1);
		if(x % m != m-1 && size[x+1])
			join(x, x+1);
		if(x - m >= 0 && size[x-m])
			join(x, x-m);
		if(x + m < n*m && size[x+m])
			join(x, x+m);
		//printf("%I64d\n", largest);
		if(k % q[i].first == 0 && largest * q[i].first >= k)
		{
			printf("YES\n");
			answer(x, k / q[i].first);
			return 0;
		}
	}
	printf("NO\n");
}