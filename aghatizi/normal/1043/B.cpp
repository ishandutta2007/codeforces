#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

int a[maxn] , b[maxn];

bool is[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i] , b[i] = a[i] - a[i - 1];

	memset(is , 1 , sizeof is);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(b[i] != b[j])
				is[j - i] = 0;

	vector<int> ans;
	for(int i = 1; i <= n; i++)
		if(is[i])
			ans.pb(i);

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
}