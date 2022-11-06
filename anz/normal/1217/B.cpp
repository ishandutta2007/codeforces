
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
#include <ctime>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
 
ll n, x;
ll d[101], h[101];
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
 
	int T; cin >> T;
	while (T--)
	{
		cin >> n >> x;
		ll maxBlow = 1;
		ll rmBlow = 0;
 
		for (int i = 0; i < n; i++)
		{
			cin >> d[i] >> h[i];
			maxBlow = max(maxBlow, d[i]);
			rmBlow = max(rmBlow, d[i] - h[i]);
		}

if (x<=maxBlow) { cout << "1\n";
 continue;}
		if (rmBlow <= 0)
		{


			cout << "-1\n";
			continue;
		}
 
		ll remain = x - maxBlow;
		ll res = remain / rmBlow + 1;
		if (remain % rmBlow) res++;
		cout << res << "\n";
	}
}