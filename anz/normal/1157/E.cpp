#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int n;
int a[200001];

int nx[200001];

int cnt[200001];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);

		cnt[t]++;
	}

	for (int i = 0; i < n; i++)
	{
		nx[i] = (i + 1) % n;
	}

	for (int i = 0; i < n; i++)
	{
		int cn = a[i];

		int htb = (n - cn) % n;

		vector <int> noDab;
		while(!cnt[htb])
		{
			noDab.push_back(htb);
			htb = nx[htb];
		}

		for (int j = 0; j < noDab.size(); j++)
		{
			nx[noDab[j]] = htb;
		}

		printf("%d ", (a[i]+htb)%n);
		cnt[htb]--;
	}
}