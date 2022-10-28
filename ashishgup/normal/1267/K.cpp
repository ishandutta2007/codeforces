#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int nCr[100][100];
int fact[N], invfact[N];

void precompute()
{
	nCr[0][0] = 1;
	for(int i = 1; i <= 50; i++)
	{
		nCr[i][0] = 1;
		nCr[i][i] = 1;
		for(int j = 1; j < i; j++)
		{
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
}

int n;

int work(map<int, int> &m)
{
	int n = 0;
	for(auto &it:m)
		n += it.second;
	auto it = --m.end();
	int ans = 1;
	int taken = 0;
	while(true)
	{
		int x = it -> first;
		int f = it -> second;
		int N = n - max(0LL, (x - 1));
		N -= taken;
		ans *= nCr[N][f];
		taken += f;
		if(it == m.begin())
			break;
		it--;
	}
	return ans;
}
int32_t main()
{
	IOS;
	precompute();
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		map<int, int> m;
		for(int i = 2; n > 0; i++)
		{
			m[n % i]++;
			n /= i;
		}
		int ans = work(m);
		if(m.count(0))
		{
			m[0]--;
			ans -= work(m);
		}
		cout << ans - 1 << endl;
	}
	return 0;
}