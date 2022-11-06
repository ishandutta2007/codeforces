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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;

int n, m;
set <pii> s;
int a[N];

vector <pair<pii, int> > query;
int ans[N];
ordered_set os;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert({ a[i],-i });
		os.insert(i);
	}

	cin >> m;
	for(int i=0;i<m;i++)
	{
		int a, b; cin >> a >> b;
		query.push_back({ { a,b },i });
	}

	int curErase = 0;
	sort(query.rbegin(), query.rend());

	for (auto it : query)
	{
		int a = it.first.first, b = it.first.second;
		while (n - a > curErase)
		{
			auto it = s.begin();
			os.erase(-(it->second));
			s.erase(it);
			curErase++;
		}

		ans[it.second] = *(os.find_by_order(b - 1));
	}

	for (int i = 0; i < m; i++)
		cout << a[ans[i]] << '\n';
}