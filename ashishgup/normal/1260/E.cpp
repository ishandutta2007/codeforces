#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = ((1 << 18) + 5);

int n, cost = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	reverse(a + 1, a + n + 1);
	priority_queue<int, vector<int>, greater<int> > pq;
	int canTake = n / 2;
	int cur = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == -1)
			break;
		if(cur == 0)
		{
			pq.push(a[i]);
			cost += pq.top();
			pq.pop();
			cur += canTake - 1;
			canTake /= 2;
		}
		else
		{
			pq.push(a[i]);
			cur--;
		}
	}
	cout << cost;
	return 0;
}