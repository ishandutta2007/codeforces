#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <string>
using namespace std;
const int N = 2002;
const long long INF = 99999999999999;
struct ban1
{
	int first, second;
};
struct ban
{
	long long gum;
	/*pair<int, int>*/ban1 x;
};
bool operator<(const ban& a, const ban& b)
{
	return a.gum < b.gum;
}

int  n, m;
long long a[N], b[N];
long long sa, sb;
long long ans0=INF;
long long ans1=INF;
long long ans2=INF;
int an1[2];
int ka, kb;
/*pair<int, int>*/ban1 an2[2];
ban za[(N*N)/2], zb[(N*N)/2];

long long myabs(long long x)
{
	if (x < 0)
		x = -x;
	return x;
}
//map<long long,bool> mp,mp0;
void byn(ban k)
{
	long long x = sa - sb + k.gum;
	ban t;
	t.gum = x;
	ban* y=lower_bound(za,za+ka,t);
	//////////////////////////////
	int p = y - za;
	int me;
	for (me = p-1; me <= p; ++me)
	{
		if (me>=0 && me<ka && myabs(x - za[me].gum) < ans2)
		{
			ans2 = myabs(x - za[me].gum);
			an2[0] = za[me].x;
			an2[1] = k.x;
		}
	}
}
int main()
{
	int i, j;
	//input
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%I64d", &a[i]);
		sa += a[i];
	}
	scanf("%d", &m);
	for (i = 0; i < m; ++i)
	{
		scanf("%I64d", &b[i]);
		sb += b[i];
	}
	//0
	ans0 = myabs(sa - sb);
	//1
	long long pq;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if (ans1 > (pq=myabs(sa - a[i] + b[j] - (sb + a[i] - b[j]))))
			{
				ans1 = pq;
				an1[0] = i;
				an1[1] = j;
			}
		}
	}
	//2
	if (n >= 2 && m >= 2)
	{
		ka = 0;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < i; ++j)
			{
				pq = ((a[i] + a[j])<<1);
//				if (mp[pq])
//					continue;
//				mp[pq] = true;
				za[ka].gum = pq;
				za[ka].x.first = i;
				za[ka].x.second = j;
				++ka;
			}
		}
		kb = 0;
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < i; ++j)
			{
				pq = ((b[i] + b[j])<<1);
//				if (mp0[pq])
//					continue;
//				mp0[pq]=true;
				zb[kb].gum = pq;
				zb[kb].x.first = i;
				zb[kb].x.second = j;
				++kb;
			}
		}
		sort(za, za + ka);
		for (i = 0; i < kb; ++i)
		{
			byn(zb[i]);
		}
	}
	//output
	if (ans0 <= ans1 && ans0 <= ans2)
	{
		cout << ans0 << endl;
		cout << '0' << endl;
//		system("pause");
		return 0;
	}
	if (ans1 <= ans2)
	{
		cout << ans1 << endl;
		cout << '1' << endl;
		cout << an1[0] + 1 << ' ' << an1[1] + 1 << endl;
//		system("pause");
		return 0;
	}
	cout << ans2 << endl;
	cout << '2' << endl;
	cout << an2[0].first + 1 << ' ' << an2[1].first + 1 << endl;
	cout << an2[0].second + 1 << ' ' << an2[1].second + 1 << endl;
//	system("pause");
	return 0;
}