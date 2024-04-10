#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int mod = 1e9 + 7;

int val[maxn] , l[maxn] , r[maxn] , len[maxn];

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

int e2(int a , int b)
{
	int tmp = max(0 , min(r[a] , r[b]) - max(l[a] , l[b]) + 1);
	return tmp;
}

int e3(int a , int b , int c)
{
	return max(0 , min({r[a] , r[b] , r[c]}) - max({l[a] , l[b] , l[c]}) + 1);
}

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> l[i];
	
	for(int i = 0; i < n; i++)
		cin >> r[i] , len[i] = r[i] - l[i] + 1;

	int res = 0 , sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(i)
		{
			val[i] = (1LL * len[i] * len[i - 1] - e2(i , i - 1)) % mod;
			val[i] = 1LL * val[i] * bpw(1LL * len[i] * len[i - 1] % mod , mod - 2) % mod;
		}
		else
			val[i] = 1;

		mkay(res += val[i]);
	}

	mkay(res += 2LL * val[1] % mod);
	for(int i = 2; i < n; i++)
	{
		mkay(sum += val[i - 2]);
		mkay(res += 2LL * val[i] * sum % mod);

		int tmp = 0;
		mkay(tmp += 1LL * len[i - 2] * len[i - 1] % mod * len[i] % mod);
		mkay(tmp -= 1LL * e2(i - 2 , i - 1) * len[i] % mod);
		mkay(tmp -= 1LL * len[i - 2] * e2(i - 1 , i) % mod);
		mkay(tmp += e3(i - 2 , i - 1 , i));

		tmp = 1LL * tmp * bpw(1LL * len[i - 2] * len[i - 1] % mod * len[i] % mod , mod - 2) % mod;
		mkay(res += 2LL * tmp % mod);
	}

	cout << res << endl;
}