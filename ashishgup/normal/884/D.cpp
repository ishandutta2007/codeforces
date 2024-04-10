
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int n, ans = 0;
int a[N];
priority_queue<int, vector<int>, greater<int> > pq;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pq.push(a[i]);
	}
	if(n % 2 == 0)
		pq.push(0);
	while(pq.size() > 1)
	{
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();
		int z = pq.top();
		pq.pop();
		ans += (x + y + z);
		pq.push(x + y + z);
	}
	cout << ans;
	return 0;
}