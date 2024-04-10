#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n , k;
	cin >> n >> k;

	n = min(n , k - 1);

	ll l = (k + 2) / 2;
	ll r = n;

	cout << max(0LL , r - l + 1) << endl;

}