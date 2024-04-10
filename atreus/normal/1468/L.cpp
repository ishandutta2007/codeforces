#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll mult(ll x, ll y, ll p){
	if (x == 0)
		return 0;
	ll ret = 2LL*mult(x/2,y,p)%p;
	if (x & 1)
		ret = (ret+y)%p;
	return ret;
}

ll power(ll x, unsigned long long y, ll p) 
{ 
	ll res = 1;	 // Initialize result 
	x = x % p; // Update x if it is more than or 
	
	while (y > 0) 
	{ 
		if (y & 1) 
			res = mult(res,x, p); 

		y = y>>1; 
		x = mult(x,x,p); 
	} 
	return res; 
} 

bool miillerTest(ll d, ll n) 
{ 
	ll a = 2 + rng() % (n - 4); 

	ll x = power(a, d, n); 

	if (x == 1 || x == n-1) 
	return true; 

	while (d != n-1) 
	{ 
		x = mult(x,x,n); 
		d *= 2; 

		if (x == 1)	 return false; 
		if (x == n-1) return true; 
	} 
	
	return false; 
} 

bool isPrime(ll n, ll k) 
{ 
	if (n <= 1 || n == 4) return false; 
	if (n <= 3) return true; 

	ll d = n - 1; 
	while (d % 2 == 0) 
		d /= 2; 

	// Iterate given nber of 'k' times 
	for (ll i = 0; i < k; i++) 
		if (!miillerTest(d, n)) 
			return false; 

	return true; 
}

map<ll,ll> pfac;
map<ll,bool> comefast;
map<ll,vector<ll>> ind;
bool sieve[maxn], mark[maxn];
ll a[1000 + 10];
bool notprime[1000+10];
map<ll,ll> pcnt;

bool cmpFunc(pair<ll,ll> fi, pair<ll,ll> se){
	return comefast[fi.second] > comefast[se.second];
}

int main(){
	ios_base::sync_with_stdio(false);
	ll N = 1000'000;
	for (ll i = 2; i <= N; i++){
		if (sieve[i])
			continue;
		ll x = i;
		while (true){
			pfac[x] = i;
			if (log2(x) + log2(i) <= 60)
				x *= i;
			else
				break;
		}
		for (ll j = i+i; j <= N; j += i)
			sieve[j] = 1;
	}
	ll n, k;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
		if (pfac.count(a[i])){
			pcnt[pfac[a[i]]]++;
			ind[pfac[a[i]]].push_back(a[i]);
		}
		else if (isPrime(a[i],100)){
			pcnt[a[i]] ++;
			ind[a[i]].push_back(a[i]);
		}
		else{
			ll sq = sqrt(a[i]);
			if (sq*sq == a[i] and isPrime(sq,100)){
				pcnt[sq] ++;
				ind[sq].push_back(a[i]);
			}
		}
	}
	if (k == 1)
		return cout << 0 << endl, 0;
	vector<ll> chert;
	for (auto it : pcnt)
		if (it.second == 1)
			chert.push_back(it.first);
	for (auto it : chert)
		pcnt.erase(it);

	vector<pair<ll,ll>> primes;
	for (auto [x,y] : pcnt)
		primes.push_back({y,x});
	sort(primes.rbegin(),primes.rend());

	ll sum = 0;
	for (auto [x,y] : primes)
		sum += x;

	ll best = 1, mnm = n + 1;
	for (ll i = 1; i <= n; i++){
		ll x = a[i];
		ll cnt = 0;
		for (auto [q,p] : primes){
			if (x % p != 0)
				continue;
			cnt ++;
			while (x % p == 0)
				x /= p;
		}
		if (x != 1 or cnt == 1)
			continue;
		mark[i] = 1;
		if (cnt < mnm)
			mnm = cnt, best = i;
		sum++;
	}
	if (sum < k)
		return cout << 0 << endl, 0;
	if (2*primes.size() <= k){
		for (auto [q,p] : primes)
			cout << ind[p][0] << " " << ind[p][1] << " ";
		k -= 2*primes.size();
		for (auto [q,p] : primes)
			for (ll j = 2; k > 0 and j < ind[p].size(); j++, k--)
				cout << ind[p][j] << " ";
		for (ll j = 1; k > 0 and j <= n; j++){
			if (mark[j]){
				k --;
				cout << a[j] << " ";
			}
		}
		cout << '\n';
		return 0;
	}
	assert(!primes.empty());
	if (primes[0].first > 2){
		for (auto [q,p] : primes){
			if (k < 2)
				break;
			cout << ind[p][0] << " " << ind[p][1] << " ";
			k -= 2;
		}
		if (k == 1)
			cout << ind[primes[0].second][2];
		cout << '\n';
		return 0;
	}
	if (2*mnm + 1 > k and k & 1)
		return cout << 0 << endl, 0;
	ll tmp = a[best];
	for (auto [q,p] : primes)
		if (a[best] % p == 0)
			comefast[p] = 1;
	sort(primes.begin(),primes.end(),cmpFunc);
	for (auto [q,p] : primes){
		if (k < 2)
			break;
		cout << ind[p][0] << " " << ind[p][1] << " ";
		k -= 2;
	}
	if (k == 1)
		cout << a[best] << '\n';
}