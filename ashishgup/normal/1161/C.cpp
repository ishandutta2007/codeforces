#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	auto it = *m.begin();
	if(it.second <= n / 2)
		cout << "Alice";
	else
		cout << "Bob";
	return 0;
}