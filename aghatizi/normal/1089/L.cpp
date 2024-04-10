#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> p[maxn];

int a[maxn] , b[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> a[i] , a[i]--;
	for(int i = 0; i < n; i++)
		cin >> b[i];

	for(int i = 0; i < n; i++)
		p[a[i]].pb(b[i]);

	int tmp = 0;
	for(int i = 0; i < k; i++)
		tmp += p[i].empty();

	vector<int> all;

	for(int i = 0; i < k; i++)
	{
		if(p[i].empty())
			continue;
		sort(p[i].begin() , p[i].end());
		p[i].pop_back();

		for(auto x : p[i])
			all.pb(x);
	}

	sort(all.begin() , all.end());
	ll res = 0;
	for(int i = 0; i < tmp; i++)
		res += all[i];

	cout << res << endl;
}