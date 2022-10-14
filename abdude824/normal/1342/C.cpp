#include<bits/stdc++.h>

using namespace std;

const int N = 40043;

int len;
int p[N];

void build(int a, int b)
{
	len = a * b;
	p[0] = 0;
	for(int i = 1; i <= len; i++)
	{
		p[i] = p[i - 1];
		if((i % a) % b != (i % b) % a)
			p[i]++;
	}
}

long long query(long long l)
{
	long long cnt = l / len;
	int rem = l % len;
	return p[len] * 1ll * cnt + p[rem]; 
}

long long query(long long l, long long r)
{
	return query(r) - query(l - 1);
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a, b, q;
		cin >> a >> b >> q;
		build(a, b);
		long long l, r;
		for(int j = 0; j < q; j++)
		{
			cin >> l >> r;
			cout << query(l, r) << " ";
		}
		cout << endl;
	}
}