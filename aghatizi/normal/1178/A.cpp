#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn] , ind[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> ans;
	int sum = 0 , ts = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		if(!i || a[0] >= a[i] * 2)
			ans.pb(i) , ts += a[i];
	}

	if(ts * 2 <= sum)
		ans.clear();

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x + 1 << " ";
	cout << endl;
}