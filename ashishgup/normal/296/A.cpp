#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n;
int a[N];
map<int, int> freq;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		freq[a[i]]++;
	}
	int mx = (n + 1) / 2;
	for(auto &it:freq)
	{
		if(it.second > mx)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}