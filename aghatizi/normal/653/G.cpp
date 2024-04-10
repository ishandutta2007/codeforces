#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;
const int maxb = 20;
const int mod = 1e9 + 7;

int t[maxn][maxb] , p[maxn] , s[maxn] , pr[maxn];

int fac[maxn] , caf[maxn];

void mkay(int &a)
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
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

int c(int s , int r)
{
	if(r < 0 || r > s)
		return 0;

	int ans = 1LL * fac[s] * caf[r] % mod;
	ans = 1LL * ans * caf[s - r] % mod;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = bpw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	for(int i = 2; i < maxn; i++)
		if(!pr[i])
			for(int j = i; j < maxn; j += i)
				pr[j] = i;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		while(x > 1)
		{
			int k = pr[x] , pw = 0;

			while(x % k == 0)
				x /= k , pw++;

			t[k][pw]++;
		}
	}

	int res = 0;
	for(int i = 2; i < maxn; i++)
		if(pr[i] == i)
		{
			memset(s , 0 , sizeof s);
			memset(p , 0 , sizeof p);

			int tmp = 0;
			for(int j = 0; j < maxb; j++)
				tmp += t[i][j];
			t[i][0] += n - tmp;

			for(int j = maxb - 2; j >= 0; j--)
				s[j] = s[j + 1] + t[i][j];
			for(int j = 0; j < maxb; j++)
				p[j + 1] = p[j] + t[i][j];

			for(int j = 1; j < maxb; j++)
			{
				int L = bpw(2 , p[j]) , R = 0;

				for(int k = 0; k <= s[j]; k++)
				{
					mkay(L -= c(p[j] , k));
					mkay(R += 1LL * c(p[j] , k) * k % mod);

					mkay(res += (1LL * L * c(s[j] , k) % mod) * k % mod);
					mkay(res += 1LL * R * c(s[j] , k) % mod);
				}
			}
		}

	cout << res << endl;

}