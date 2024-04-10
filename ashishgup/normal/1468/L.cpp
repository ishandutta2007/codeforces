#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long
 
const int N = 1e3 + 5;
 
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double
 
typedef unsigned long long ull;
 
 
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
 
 
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}
 
ull pollard(ull n) {
	auto f = [n](ull x) { return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 0, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ll> factor(ll n) {
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	sort(all(l));
	return l;
}

int n, k;
int a[N];
map<int, int> m;
map<int, vector<int> > pos;
vector<int> store[N];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		store[i] = factor(a[i]);
		set<int> s;
		for(auto &it:store[i])
			s.insert(it);
		store[i] = vector<int>(s.begin(), s.end());
		if(s.size() == 1)
		{
			m[*s.begin()]++;
			pos[*s.begin()].push_back(a[i]);
		}
	}
	vector<pair<int, int> > primes;
	for(auto &it:m)
	{
		if(it.second > 1)
			primes.push_back({it.second, it.first});
	}
	int extra = 0, sum = 0;
	sort(primes.rbegin(), primes.rend());
	multiset<int> have, canErase;
	for(auto &it:primes)
	{
		sum += it.first;
		extra += it.first - 2;
		int ctr = 0;
		for(auto &p:pos[it.second])
		{
			have.insert(p);
			ctr++;
			if(ctr >= 3)
				canErase.insert(p);
		}
		if(sum >= k && sum - extra <= k)
		{
			while(sum > k)
			{
				sum--;
				auto val = canErase.begin();
				have.erase(have.find(*val));
				canErase.erase(val);
			}
			for(auto &it:have)
				cout << it << " ";
			return 0;
		}
	}
	if(sum <= k)
	{
		set<int> s;
		for(int i = 1; i <= n; i++)
		{
			if(store[i].size() == 1)
				continue;
			int flag = 1;
			for(auto &it:store[i])
				flag &= (m[it] >= 2);
			if(flag)
			{
				have.insert(a[i]);
				sum++;
			}
			if(sum == k)
			{
				for(auto &it:have)
					cout << it << " ";
				return 0;
			}
		}
		cout << 0;
		return 0;
	}
	int mxP = (k - 1) / 2;
	for(int i = 1; i <= n; i++)
	{
		if(store[i].size() == 1 || store[i].size() > mxP)
				continue;
		int flag = 1;
		map<int, int> current;
		for(auto &it:store[i])
		{
			current[it] = 1;
			flag &= (m[it] >= 2);
		}
		if(flag)
		{
			vector<int> cur;
			for(auto &it:m)
				cur.push_back(it.first);
			have.insert(a[i]);
			sum++;
			for(auto &it:cur)
			{
				if(current[it])
					continue;
				if(sum > k)
				{
					for(auto &val:pos[it])
					{
						sum--;
						have.erase(have.find(val));
					}
				}
			}
			if(sum == k)
			{
				for(auto &it:have)
					cout << it << " ";
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}