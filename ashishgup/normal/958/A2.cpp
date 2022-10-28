#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update > pbds;

#define print_time cerr << "Time elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

#define int long long
//#define float long double

const int N = 2005;
const int M = 205;
const int BASE = 22222223;
const int MOD = 1e9 + 7;

string T[M];
namespace H1 {
 
	long long mod = 1000000007LL;
 
	long long power(long long a, long long b)
	{
		long long ret = 1;
		while(b)
		{
			if(b&1)
				ret = (ret * a) % mod;
			a = (a * a) % mod;
			b /= 2;
		}
		return ret;
	}
 
 
	long long inv(long long x)
	{
		return power(x, mod - 2);
	}
 
	long long base = 22222223;
	long long val[205][100001];
	long long invPow[100001];
 
	long long getHash(int start, int len, int id)
	{
		start--;
		long long v = val[id][start + len] - val[id][start];
		v %= mod;
		if(v < 0) v += mod;
		v *= invPow[start];
		v %= mod;
		return v;
	}
 
 
 
	void prepare(int id)
	{
		invPow[0] = 1;
		invPow[1] = inv(base);
		for(int i = 2; i <= 100000; i++)
			invPow[i] = (invPow[i-1] * invPow[1]) % mod;
		val[id][0] = 0;
		long long weight = 1;
		for(int i = 0; i < T[id].size(); i++)
		{
			val[id][i+1] = (val[id][i] + (long long)T[id][i] * weight) % mod;
			weight = (weight * base) % mod;
		}
	}
 
}
using namespace H1;

string A[N];
int n, m, pw[N];
map<int, int> Hash;
int pre[M][N];
int gethash(string s) {
	int val = 0, weight = 1;
	for(int i = 0; i < s.size(); i++)
	{
		val = (val + (long long)s[i] * weight) % mod;
		weight = (weight * base) % mod;
	}
	return val;
}

int32_t main(){
	pw[0] = 1;
	for (int i = 1; i < N; i++)
		pw[i] = (pw[i - 1] * BASE) % MOD;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		Hash[i] = gethash(A[i]);
	}
	for (int i = 1; i <= m; i++) {
		cin >> T[i];
		prepare(i);
	}



	for (int i = 1; i <= n; i++) {
		int L = i, R = L + m - 1;
		if (R > n) break;

		int hash = getHash(L, m, 1);

		for (int k = 1; k <= n; k++) {
			if (k + m - 1 > n) break;
			if (Hash[k] != hash) continue;

			bool okk = 1;
			for (int j = 2; j <= m; j++) {
				int hash = getHash(L, m, j);
				if (Hash[k + j - 1] != hash) {
					okk = 0;
					break;
				}
			}
			if (okk) {
				cout << k << " " << i << endl;
				return 0;
			}
		}
	}


	print_time
}