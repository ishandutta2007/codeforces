#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int q, x;
int mark[N], cur[N];

int32_t main()
{
	IOS;
	cin >> q >> x;
	for(int i = 0; i < N; i++)
		cur[i] = i;
	int ans = 0;
	while(q--)
	{
		int y;
		cin >> y;
		y %= x;
		while(cur[y] < N && mark[cur[y]])
			cur[y] += x;
		if(cur[y] < N)
			mark[cur[y]] = 1;
		while(mark[ans])
			ans++;
		cout << ans << endl;
	}
	return 0;
}