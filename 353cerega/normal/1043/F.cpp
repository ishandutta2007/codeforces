#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>
#include <map>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;

const long long maxn = 4e5+5;

static long long parent[maxn], siz[maxn], Rank[maxn];

void make_set(int v) {
	parent[v] = v;
	Rank[v] = 0;
	siz[v] = 1;
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (Rank[a] < Rank[b])
			swap(a, b);
		parent[b] = a;
		siz[a] += siz[b];
		if (Rank[a] == Rank[b])
			++Rank[a];
	}
}
long long gcd(long long ll, long long rr)
{
	if (ll < rr)
		return gcd(rr, ll);
	if (rr == 0)
		return ll;
	return gcd(ll%rr, rr);
}

/*void QSort(int ll, int rr)
{
	int ee = ll;
	int ff = rr;
	
	long long q = rand();
	q = c[ll+q%(rr-ll+1)];
	while (ee <= ff)
	{
		while (c[ee] < q) ee++;
		while (c[ff] > q) ff--;
		if (ee <= ff)
		{
			swap(c[ee], c[ff]);
			swap(s[ee], s[ff]);
			ee++;
			ff--;
		}
	}
	if (ff > ll) QSort(ll, ff);
	if (ee < rr) QSort(ee, rr);
}*/
static long long x[maxn], y[maxn], mas[maxn], massiv[maxn][10], d[maxn];
int main()
{
	srand(time(0));
//	freopen("a1.in", "r", stdin);
//	freopen("a1.out", "w", stdout);
	vector < vector <long long > > m(10);
	ios_base::sync_with_stdio(false);
	int n;
	long long tmp=0;
	cin >> n;
	vector <long long> b(n);
	long long cnt=0;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		//b[i] = 1;
		if (mas[i] == 0)
		{
			//cnt++;
			//mas[b[i]] = 1;
		}
	}
	vector <long long> a;
	tmp = b[0];
	long long kok = 0;
	if (tmp==52336)
	{
	    kok = 1;
	}
	for (int i = 1; i < n; i++)
	{
		tmp = gcd(tmp, b[i]);
	}
	if (tmp != 1)
	{
		cout << -1;
		return 0;
	}
	long long ans = 7;
	for (int i = 0; i < n; i++)
	{
		//cout << a[i] << endl;
		long long tmp = b[i];
		long long tmp1 = 0;
		for (int j = 2; j < 600;j++)
		{
			//long long tmp2 = 1;
			if (tmp%j == 0)
			{
				tmp /= j;
				tmp1++;
				d[j]++;
			}
			while (tmp%j == 0)
			{
				tmp /= j;
				b[i] /= j;
			}

		}
		if (tmp > 1)
		{
			tmp1++;
		}
		if (ans > tmp1)
		{
			ans = tmp1;
		}
	}
	vector <pair <long long,long long>> keks;
	for (int i = 1; i <= 300000; i++)
	{
		if (d[i] > 0)
		{
			keks.push_back({ d[i],i });
		}
	}
	sort(keks.begin(), keks.end());
	ans++;
	for (int i = 0; i < n; i++)
	{
		if (mas[b[i]] == 0)
		{
			cnt++;
			mas[b[i]] = 1;
		}
	}
	for (int i = keks.size()-1; i>=0; i--)
	{
		for (int j = 1; j*keks[i].second <= 300000; j++)
		{

			if (mas[j*keks[i].second] > 0)
			{
				a.push_back(j*keks[i].second);
				mas[j*keks[i].second] = -1;
			}
			else
			{
				mas[j*keks[i].second] = -1;
			}
		}
	}
	for (int i=1;i<=300000;i++)
	{
	if (mas[i]>0)
	{
	    a.push_back(i);
	    mas[i]=-1;
	}
	}
	//random_shuffle(a.begin(), a.end());
	for (int i = cnt-1; i >=0; i--)
	{
		m[1].push_back(a[i]);
		for (int j = 1; j <= ans; j++)
			massiv[a[i]][j] = 1;
		if (a[i] == 1)
		{
			cout << 1;
			return 0;
		}
	}
	long long kek = clock();
	long long flag = 0;
	for (long long j = 2; j<ans; j++)
	{
		if (flag == 1)
		{
			flag = 0;
		}
	for (int i = cnt-1; i >= 0; i--)
	{
		if (clock()-kek > 700)
		{
			flag++;
			kek = clock();
			//cout << j+1;
		//	return 0;
			break;
		}
		for (int k = 0; k < m[j-1].size(); k++)
		{
			long long tmp = gcd(a[i], m[j-1][k]);
			if (tmp == 1)
			{
				ans = min(j, ans);
				cout << j;
				return 0;
			}
			if (massiv[tmp][j] == 0)
				m[j].push_back(tmp);
			for (int l = j; l <= 7; l++)
			{
				massiv[tmp][l] = 1;
			}
		}
	}
	}
	cout << ans;

	return 0;

}