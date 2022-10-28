#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6 + 5;
const int M = 1e7 + 5;

int n;
int a[N];
int vis[M], pos[M];
bool have[M];
int mn[M], mnidx[M], mn2[M], mn2idx[M];

void work()
{
	for(int i = 1; i < M; i++)
	{
		for(int j = 1; i * j < M; j++)
		{
			if(have[i * j])
			{
				int x = j;
				if(x < mn[i])
				{
					mn2[i] = mn[i], mn2idx[i] = mnidx[i];
					mn[i] = x, mnidx[i] = pos[i * j];
				}
				else if(x < mn2[i])
					mn2[i] = x, mn2idx[i] = pos[i * j];
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	long long lcm = 1e18, idxi = 1, idxj = 2;
	for(int i = 1; i < M; i++)
	{
		mn[i] = 1e9;
		mn2[i] = 1e9;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(have[a[i]])
		{
			if(a[i] < lcm)
			{
				lcm = a[i];
				idxi = pos[a[i]];
				idxj = i;
				mn[lcm] = 1;
				mn2[lcm] = 1;
				mnidx[lcm] = idxi;
				mn2idx[lcm] = idxj;
			}
		}
		have[a[i]] = 1;
		pos[a[i]] = i;
	}
	work();
	int idx = lcm;
	for(int i = 1; i < M; i++)
	{
		if(mn2[i] == 1e9)
			continue;
		long long curlcm = 1LL * i * mn[i] * mn2[i];
		if(curlcm < lcm)
		{
			lcm = curlcm;
			idx = i;
		}
	}
	idxi = mnidx[idx];
	idxj = mn2idx[idx];
	if(idxi > idxj)
		swap(idxi, idxj);
	cout << idxi << " " << idxj;
	return 0;
}