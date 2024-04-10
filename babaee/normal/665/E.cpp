#pragma GCC optimization("O0")
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const int maxn = 1e6+10;
const int lgmx = 30;

int trie[maxn * lgmx][2];
ll sbtrcnt[maxn * lgmx];
int arr[maxn];
int vcnt = 1;


inline void add_elmnt(int x)
{
	int v = 0;
	for(int i = lgmx-1; i >= 0; i--)
	{
		bool ch = ((x >> i) & 1);
		if(trie[v][ch] == 0)
			trie[v][ch] = vcnt++;
		v = trie[v][ch];
		sbtrcnt[v]++;
	}
}

inline ll count_grtrs(int x, int k)
{
	int v = 0;
	ll out = 0;
	for(int i = lgmx-1; i >= 0; i--)
	{
		bool xch = (x >> i) & 1;
		bool kch = (k >> i) & 1;
		if(kch == 0 and trie[v][xch ^ 1] != 0) // counting strictly greaters
		{
			out += sbtrcnt[trie[v][xch^1]];
		}
		if(i == 0) // counting equals
		{
			if(trie[v][xch ^ kch] != 0)
				out += sbtrcnt[trie[v][xch^kch]];
		}
		if(trie[v][xch ^ kch] == 0)
		{
			return out;
		}
		v = trie[v][xch ^ kch];
	}
	return out;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int pxor = 0;
	ll ans = 0;
	add_elmnt(pxor);
	for(int i = 0; i < n; i++)
	{
		pxor = (pxor ^ arr[i]);
		ans += count_grtrs(pxor, k);
		add_elmnt(pxor);
	}
	cout << ans << endl;
	return 0;
}