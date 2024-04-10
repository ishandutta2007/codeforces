#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

bool is[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 2; i < maxn; i++)
		if(!is[i])
			for(ll j = 1LL * i * i; j < maxn; j += i)
				is[j] = 1;

	int n;
	cin >> n;

	if(n < 3)
		return cout << -1 << endl , 0;

	int shit = -1;
	for(int i = n; shit == -1; i++)
		if(!is[i])
			shit = i;

	while(shit > n + n / 2);

	vector<pair<int , int> > res;
	for(int i = 0; i < n; i++)
		res.pb({i , (i + 1) % n});

	for(int i = 0; i < shit - n; i++)
		res.pb({i , n / 2 + i});

	cout << res.size() << endl;
	for(auto x : res)
		cout << x.first + 1 << " " << x.second + 1 << endl;
}