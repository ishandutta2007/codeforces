#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = (int)2e5 + 3;
typedef long double ld;
const ld infint = (ld)1e15;
const ll inf = (ll)1e18;
const int MAXN = 707;
map<ll, ll> M;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--)
	{
		ll n;
		cin >> n;
		ll t = -1;
		M.clear();
		for (int i = 0; i < n; i++)
		{
			ll a;
			cin >> a;
			M[a]++;
			if(M[a] >= 4)
				t = a;
		}
		if(t != -1)
		{
			cout << t << " " << t << " " << t << " " << t << "\n";
			continue;
		}
		vector<ll> p;
		for (auto u : M)
			if(u.second >= 2)
				p.push_back(u.first);
		sort(p.begin(), p.end());
		ld mn = infint;
		ll id = -1;
		for (int i = 1; i < p.size(); i++){
            //cerr << setprecision(16) << mn << " ";
			if((1.00 * p[i - 1] / p[i]) + (1.00 * p[i] / p[i - 1]) < mn)
				mn = (p[i] * p[i] + p[i - 1] * p[i - 1]) /1.0/ (p[i] * p[i - 1]), id = i;
		}
		cout << p[id - 1] << " " << p[id - 1] << " " << p[id] << " " << p[id] << "\n";
	}
}