#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n;
int cnt = 0;
bool vis[N];
int xorVal = 0;
vector<int> grundy = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i * i <= n; i++)
	{
		if(vis[i])
			continue;
		int x = i;
		vis[x] = 1;
		int curCnt = 1;
		while(x * i <= n)
		{
			if(x == 1)
				break;
			x *= i;
			if(x < N)
				vis[x] = 1;
			curCnt++;
		}
		xorVal ^= grundy[curCnt];
		cnt += curCnt;
	}
	xorVal ^= ((n - cnt) % 2);
	if(!xorVal)
		cout << "Petya";
	else
		cout << "Vasya";
	return 0;
}