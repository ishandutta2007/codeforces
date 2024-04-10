#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

int l[maxn] , r[maxn] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> l[i];
	for(int i = 0; i < n; i++)
		cin >> r[i];

	vector<int> shits;

	for(int i = 0; i < n; i++)
		shits.pb(l[i] + r[i]);

	sort(shits.begin() , shits.end());
	shits.resize(unique(shits.begin() , shits.end()) - shits.begin());

	for(int i = 0; i < n; i++)
		a[i] = n - (lower_bound(shits.begin() , shits.end() , l[i] + r[i]) - shits.begin());

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
			if(a[j] > a[i])
				l[i]--;
		for(int j = i + 1; j < n; j++)
			if(a[j] > a[i])
				r[i]--;

		if(l[i] != 0 || r[i] != 0)
			return cout << "NO" << endl , 0;
	}

	cout << "YES" << endl;

	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}