#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

int n, k;
int a[25];
ll kk[2];
const ll inf = 1e15;
const ll mod = 1000000007;
ll fact[25];

void gen1(int i, int m, ll sum, int taken, pair < ll, int > *res, int &res_cnt)
{
	if (i == m)
	{
		res[res_cnt].fst = sum;
		res[res_cnt].snd = taken;
		res_cnt++;
		return;
	}
	
	gen1(i+1, m, sum + a[i], taken + 1, res, res_cnt);
	gen1(i+1, m, sum, taken, res, res_cnt);
}

int mres1[532000];
int mres2[532000];

template <typename T> void mkuniq(T *arr, int *marr, int cnt, int &new_cnt)
{
	new_cnt = 0;
	
	for (int i = 0; i < cnt; i++)
	{
		int j = i;
		while (j < cnt-1 && arr[j] == arr[j+1]) j++;
		marr[new_cnt] = j - i + 1;
		arr[new_cnt] = arr[j];
		i = j;
		new_cnt++;
	}
}

ll count1(ll dist)
{
	ll ans = 0;
	
	pair < ll, int > res1[1 << 12];
	pair < ll, int > res2[1 << 12];
	int res1_cnt = 0;
	int res2_cnt = 0;
	
	gen1(0, n/2, 0, 0, res1, res1_cnt);
	gen1(n/2, n, 0, 0, res2, res2_cnt);
	
	sort(res1, res1 + res1_cnt);
	sort(res2, res2 + res2_cnt);
	
	mkuniq(res1, mres1, res1_cnt, res1_cnt);
	mkuniq(res2, mres2, res2_cnt, res2_cnt);
	
	int p1 = 0;
	int p2 = res2_cnt - 1;
	
	while (p1 < res1_cnt && p2 >= 0)
	{
		ll sum = res1[p1].fst + res2[p2].fst;
		if (sum < dist)
			p1++;
		else if (sum > dist)
			p2--;
		else
		{
			for (int i = p2; i >= 0; i--)
			{
				if (res1[p1].fst + res2[i].fst == dist)
				{
					int taken = res1[p1].snd + res2[i].snd;
					ans += ((fact[taken] * fact[n - taken]) % mod) * mres1[p1] * mres2[i];
					ans %= mod;
				}
				else
					break;
			}
			
			p1++;
		}
	}
	
	return ans;
}

void gen2(int i, int m, ll sum1, int taken1, ll sum2, int taken2,
	pair < pair < ll, ll >, pair < int, int > > *res, int &res_cnt)
{
	if (i == m)
	{
		res[res_cnt].fst.fst = sum1;
		res[res_cnt].fst.snd = sum2;
		res[res_cnt].snd.fst = taken1;
		res[res_cnt].snd.snd = taken2;
		res_cnt++;
		return;
	}
	
	gen2(i+1, m, sum1 + a[i], taken1 + 1, sum2, taken2, res, res_cnt);
	gen2(i+1, m, sum1, taken1, sum2 + a[i], taken2 + 1, res, res_cnt);
	gen2(i+1, m, sum1, taken1, sum2, taken2, res, res_cnt);
}

pair < pair < ll, ll >, pair < int, int > > res1[532000];
pair < pair < ll, ll >, pair < int, int > > res2[532000];


ll count2(ll dist1, ll dist2)
{
	ll ans = 0;
	
	
	int res1_cnt = 0;
	int res2_cnt = 0;
	
	gen2(0, n/2, 0, 0, 0, 0, res1, res1_cnt);
	gen2(n/2, n, 0, 0, 0, 0, res2, res2_cnt);
	
	sort(res1, res1 + res1_cnt);
	sort(res2, res2 + res2_cnt);
	
	
	mkuniq(res1, mres1, res1_cnt, res1_cnt);
	mkuniq(res2, mres2, res2_cnt, res2_cnt);
	
	int p1 = 0;
	int p2 = res2_cnt - 1;
	
	while (p1 < res1_cnt && p2 >= 0)
	{
		//cout << p1 << " " << p2 << endl;;
		ll sum1 = res1[p1].fst.fst + res2[p2].fst.fst;
		if (sum1 < dist1)
			p1++;
		else if (sum1 > dist1)
			p2--;
		else
		{
			ll sum2 = res1[p1].fst.snd + res2[p2].fst.snd;
			
			if (sum2 < dist2)
				p1++;
			else if (sum2 > dist2)
				p2--;
			else
			{
				for (int i = p2; i >= 0; i--)
				{
					if (res1[p1].fst.fst + res2[i].fst.fst == dist1 &&
						res1[p1].fst.snd + res2[i].fst.snd == dist2)
					{
						int taken1 = res1[p1].snd.fst + res2[i].snd.fst;
						int taken2 = res1[p1].snd.snd + res2[i].snd.snd;
						ans += (((((fact[taken1] * fact[taken2]) % mod) * 
							   fact[n - taken1 - taken2]) % mod) * mres1[p1] * mres2[i]);
						ans %= mod;
					}
					else
						break;
				}
			
				p1++;
			}
		}
	}
	
	return ans;
}


int main(int argc, char **argv)
{
	fact[0] = 1;
	for (int i = 1; i < 25; i++)
		fact[i] = (fact[i-1] * i) % mod; 
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> k;
	kk[0] = inf;
	kk[1] = inf;
	for (int i = 0; i < k; i++)
		cin >> kk[i];
		
	if (kk[0] > kk[1])
		swap(kk[0], kk[1]);
		
	ll ans = fact[n];
	ans -= count1(kk[0]);
	ans -= count1(kk[1]);
	ans += count2(kk[0], kk[1] - kk[0]);
	
	while (ans < 0) ans += mod;
	
	ans %= mod;
	
	cout << ans;
	
	return 0;
}