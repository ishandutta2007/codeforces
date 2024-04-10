#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, l, r;
int a[N], b[N];
 
int32_t main()
{
	IOS;
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	vector<int> va, vb;
	for(int i = 1; i <= n; i++)
	{
		if(i < l || i > r)
		{
			if(a[i] != b[i])
			{
				cout << "LIE";
				return 0;
			}
			continue;
		}
		va.push_back(a[i]);
		vb.push_back(b[i]);
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	if(va != vb)
		cout << "LIE";
	else
		cout << "TRUTH";
	return 0;
}