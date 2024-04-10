#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int a[212345];
vector<int> f[212345];
struct query{
	int a, b, c;
	query(int x, int y, int z) : a(x), b(y), c(z){}
};

int bit[212345];


int change(int pos)
{
	for(int i = pos; i < 212345; i += -i&i)
		bit[i]++;
}

int get(int pos)
{
	int retv = 0;
	for(int i = pos; i > 0; i -= -i&i)
		retv += bit[i];
	return retv;
}

int ans[212345];
int rdm[212345];
vector<int> ins[212345];
vector<query> q[212345];

int
main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	set<int> s;
	int sz = 0;
	
	for(int i = 1; i <= n; i++)
		if(s.find(a[i]) == s.end())
		{
			rdm[sz++] = a[i];
			s.insert(a[i]);
		}
		
	sort(rdm, rdm + sz);
	s.clear();

	for(int i = 1; i <= n; i++)
	{
		int *it = lower_bound(rdm, rdm + sz, a[i]);
		ins[it - rdm].push_back(i);
	}
	
	for(int k = 1; k <= n - 1; k++)
	{
		for(int i = 1; k*(i-1)+2 <= n; i++)
		{
			int *it = lower_bound(rdm, rdm + sz, a[i]);
			q[it - rdm].push_back(query(k*(i-1)+2, min(n, k*i +1), k));
		}
//			ans += get(1, 1, n, k*i, k*i + k - 1, a[i]);
	}
	
	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < q[i].size(); j++)
			ans[q[i][j].c] += get(q[i][j].b) - get(q[i][j].a - 1);
		for(int j = 0; j < ins[i].size(); j++)
			change(ins[i][j]);
	}
	for(int i = 1; i <= n-1; i++)
		printf("%d\n", ans[i]);
}