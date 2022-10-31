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
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull long long
#define fst first
#define snd second
#define ld long double

ll a[100005];

int main()
{
	ll n, l, r, ql, qr;;
	cin >> n >> l >> r >> ql >> qr;
	
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	ll ans = min(sum * l + (n-1) * ql, sum * r + (n-1) * qr);
	
	int left = 0, right = n-1;
	ll sumL = 0, sumR = 0;
	ll cnt = 0;
	while (right - left > 0)
	{
		sumL += a[left];
		sumR += a[right];
		cnt += 2;
		
		ans = min(ans, sumL * l + sumR * r 
		+ min((sum - sumR - sumL) * l + ql * max(0LL, n - cnt - 1), (sum - sumR - sumL) * r + qr * max(0LL, n - cnt - 1)));
		
		right--;
		left++;
	}
	
	cout << ans;

	return 0;
}