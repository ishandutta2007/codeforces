//Coding on CF IDE

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q;
int a[N], lp[N];
map<int, int> primes[N];
multiset<int> store[N];
bool sieve[N];

int pow(int a, int b, int m)
{
    int ans = 1;
    while(b > 0)
    {
        if(b & 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

void precompute()
{
    fill(sieve + 2, sieve + N + 1, 1);
    for(int i = 2; i < N; i++)
    {
        if(sieve[i])
        {
            for(int j = 1; i * j < N; j++)
            {
                lp[i * j] = i;
                sieve[i * j] = 0;
            }
        }
    }
}

int32_t main()
{
	IOS;
	precompute();
	int ans = 1;
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
	    cin >> a[i];
	    while(a[i] > 1)
	    {
	        primes[i][lp[a[i]]]++;
	        a[i] /= lp[a[i]];
	    }
	    for(auto &it:primes[i])
	        store[it.first].insert(it.second);
	}
	for(int i = 1; i < N; i++)
	{
	    if(store[i].size() == n)
	        ans = (ans * (pow(i, *store[i].begin(), MOD))) % MOD;
	}
	while(q--)
	{
	    int idx, x;
	    cin >> idx >> x;
	    map<int, int> cur;
	    while(x > 1)
	    {
	        cur[lp[x]]++;
	        x /= lp[x];
	    }
	    for(auto &it:cur)
	    {
	        if(primes[idx].find(it.first) == primes[idx].end())
	        {
	            primes[idx][it.first] = it.second;
	            store[it.first].insert(it.second);
	            if(store[it.first].size() == n)
	            {
	                ans *= pow(it.first, *store[it.first].begin(), MOD);
	                ans %= MOD;
	            }
	        }
	        else
	        {
	            int prev = primes[idx][it.first];
	            int cur = prev + it.second;
	            int prevMin = *store[it.first].begin();
	            store[it.first].erase(store[it.first].find(prev));
	            store[it.first].insert(cur);
	            int newMin = *store[it.first].begin();
	            primes[idx][it.first] = cur;
	            if(store[it.first].size() == n)
	            {
	                ans *= pow(it.first, newMin - prevMin, MOD);
	                ans %= MOD;
	            }
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}