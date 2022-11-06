#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int mod = 998244353;
const int sq = 1000;

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b & 1)
		x = 1LL * x * a % mod;

	return x;
}

int pt[maxn] , a[maxn] , sum[maxn];

int get(int l , int r)
{
	int ans = sum[r] - sum[l];
	mkay(ans);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a , a + n);
	reverse(a , a + n);

	for(int i = 0; i < n; i++)
		mkay(sum[i + 1] = sum[i] + a[i]);

	int val = bpw(n , mod - 2);
	for(int i = 1; i <= n; i++)
	{
		int res = 0;
		for(int j = 0; i * j < n; j++)
			mkay(res += 1LL * j * get(j * i , min(j * i + i , n)) % mod);

		cout << 1LL * res * val % mod << " ";
	}
	cout << endl;
}