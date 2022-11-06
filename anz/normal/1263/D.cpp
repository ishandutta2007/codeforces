#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int par[26];
int isExist[26];

int getPar(int a)
{
	if (par[a] == a) return a;
	else return par[a] = getPar(par[a]);
}
void merge(int a, int b)
{
	int pa = getPar(a), pb = getPar(b);
	if (pa == pb) return;
	par[pa] = pb;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 26; i++) par[i] = i;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ab[26] = { 0, };
		string str; cin >> str;
		for (int i = 0; i < str.size(); i++)
			ab[str[i] - 'a'] = 1;

		int last = -1;
		for (int i = 0; i < 26; i++)
		{
			if (ab[i] == 0) continue;
			isExist[i] = 1;

			if (last != -1) merge(last, i);
			last = i;
		}
	}

	set <int> ans;
	for (int i = 0; i < 26; i++)
	{
		if (!isExist[i]) continue;
		ans.insert(getPar(i));
	}

	cout << ans.size();
}