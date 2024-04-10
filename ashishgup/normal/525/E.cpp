#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 30;

int n, K, S, ans = 0;
int a[N], fact[N];
vector<int> v1, v2;
map<int, int> cnt[N];

void rec1(int idx, int k, int sum)
{
	if(sum > S)
		return;
	if(k > K)
		return;
	if(idx == v1.size())
	{
		cnt[k][sum]++;
		return;
	}
	//Don't take
	rec1(idx + 1, k, sum);
	//Take as it is
	rec1(idx + 1, k, sum + v1[idx]);
	//Use exclamation
	if(v1[idx] <= 18)
		rec1(idx + 1, k + 1, sum + fact[v1[idx]]);
}

void rec2(int idx, int k, int sum)
{
	if(sum > S)
		return;
	if(k > K)
		return;
	if(idx == v2.size())
	{
		for(int i = 0; i <= K - k; i++)
		{
			if(cnt[i].count(S - sum))
				ans += cnt[i][S - sum];
		}
		return;
	}
	//Don't take
	rec2(idx + 1, k, sum);
	//Take as it is
	rec2(idx + 1, k, sum + v2[idx]);
	//Use exclamation
	if(v2[idx] <= 18)
		rec2(idx + 1, k + 1, sum + fact[v2[idx]]);
}

int32_t main()
{
	IOS;
	cin >> n >> K >> S;
	fact[0] = 1;
	for(int i = 1; i <= 18; i++)
		fact[i] = fact[i - 1] * i;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i <= n / 2)
			v1.push_back(a[i]);
		else
			v2.push_back(a[i]);
	}
	rec1(0, 0, 0);
	rec2(0, 0, 0);
	cout << ans;
	return 0;
}