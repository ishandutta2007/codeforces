#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const ll inf = 3e18;

ll l[maxn] , r[maxn] , a[maxn] , x[maxn];

int t[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(r , r + maxn , inf);

	int n;
	ll T;
	cin >> n >> T;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
		x[i]--;

		if(x[i] < i)
			return cout << "No" << endl , 0;
	}

	for(int i = 0; i + 1 < n; i++)
		if(x[i + 1] < x[i])
			return cout << "No" << endl , 0;

	for(int i = 0; i < n; i++)
	{
		l[i] = max(l[i] , a[i] + T);

		if(x[i] + 1 < n)
			r[x[i]] = min(r[x[i]] , a[x[i] + 1] + T);

		t[i]++;
		t[x[i]]--;
	}

	for(int i = 1; i < n; i++)
		t[i] += t[i - 1];

	for(int i = n - 2; i >= 0; i--)
		r[i] = min(r[i] , r[i + 1] - 1);

	for(int i = 0; i < n; i++)
		if(t[i] > 0)
			l[i] = max(l[i] , a[i + 1] + T);

	for(int i = 1; i < n; i++)
		l[i] = max(l[i] , l[i - 1] + 1);

	for(int i = 0; i < n; i++)
		if(l[i] >= r[i] || x[i] < i)
			return cout << "No" << endl , 0;

	cout << "Yes" << endl;
	for(int i = 0; i < n; i++)
		cout << r[i] - 1 << " ";
	cout << endl;
}