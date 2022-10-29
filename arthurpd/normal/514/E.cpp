#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > mat;

mat prod(mat a, mat b)
{
	mat retv(a.size(), vector<ll> (b[0].size(), 0));
	for(int i = 0; i < retv.size(); i++)
		for(int j = 0; j < retv[i].size(); j++)
			for(int k = 0; k < b.size(); k++)
				retv[i][j] = (retv[i][j] + a[i][k] * b[k][j]) % 1000000007ll;
	return retv;
}

int main(void)
{
	int n, x, d, sz = 101;
	scanf("%d %d", &n, &x);
	mat a(sz, vector<ll> (sz, 0));
	mat res(sz, vector<ll> (sz, 0));
	for(int i = 0; i < n; /*a[sz - 1][d-1]++,*/ a[0][d-1]++, i++)
		scanf("%d", &d);
	for(int i = 0; i < sz; i++)
		res[i][i] = 1;
	for(int i = 1; i < sz - 1; i++)
		a[i][i-1]++;
	a[sz-1][0] = 1;
	a[sz - 1][sz - 1] = 1;
	
	for(int i = 30; i >= 0; i--)
	{
		res = prod(res, res);
		if(x & (1 << i))
			res = prod(a, res);
	}
	cout << (res[sz - 1][0] + res[0][0]) % 1000000007ll << endl;
}