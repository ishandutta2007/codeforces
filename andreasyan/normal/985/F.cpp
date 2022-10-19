#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
const int N = 200005;
const long long P = 3;
long long M;

int n;
char a[N];
long long p[26][N];
long long ast[N];

bool stg()
{
	if (M == 2)
		return true;
	if (M % 2 == 0)
		return false;
	for (long long i = 3; i * i <= n; i += 2)
		if (M % i == 0)
			return false;
	return true;
}

void findM()
{
	srand(time(0));
	while (1)
	{
		M = rand() % 1000000000 + 1000000000;
		if (stg())
			break;
	}
}

int main()
{
	findM();
	int q;
	cin >> n >> q >> a;
	ast[0] = 1;
	for (int i = 1; i <= n; ++i)
		ast[i] = (ast[i - 1] * P) % M;
	for (int j = 0; j < 26; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			int x = 0;
			if (a[i] - 'a' == j)
				x = 1;
			p[j][i] = ast[i] * x;
			if (i)
				p[j][i] = (p[j][i] + p[j][i - 1]) % M;
		}
	}
	while (q--)
	{
		int l1, r1, l2, r2;
		int l;
		cin >> l1 >> l2 >> l;
		--l1;
		--l2;
		if (l1 > l2)
			swap(l1, l2);
		r1 = l1 + l - 1;
		r2 = l2 + l - 1;
		vector<long long> v1, v2;
		for (int i = 0; i < 26; ++i)
		{
			long long hash;
			if (l1 == 0)
				hash = p[i][r1];
			else
				hash = (p[i][r1] - p[i][l1 - 1] + M) % M;
			hash = (hash * ast[l2 - l1]) % M;
			v1.push_back(hash);
		}
		for (int i = 0; i < 26; ++i)
		{
			long long hash;
			if (l2 == 0)
				hash = p[i][r2];
			else
				hash = (p[i][r2] - p[i][l2 - 1] + M) % M;
			v2.push_back(hash);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		if (v1 == v2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}