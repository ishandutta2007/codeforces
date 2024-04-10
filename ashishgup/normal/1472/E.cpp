//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

typedef struct node
{
	int w, h, idx;
}data;

int n;
int ans[N];
data a[N];

bool comp(data &d1, data &d2)
{
	if(d1.h != d2.h)
		return d1.h < d2.h;
	return d1.w < d2.w;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].h >> a[i].w;
			if(a[i].h > a[i].w)
				swap(a[i].h, a[i].w);
			a[i].idx = i;
			ans[i] = -1;
		}
		sort(a + 1, a + n + 1, comp);
		int l = 0, curMin = 2e9, curIdx = -1;
		for(int r = 1; r <= n; r++)
		{
			while(l + 1 < r && a[l + 1].h < a[r].h)
			{
				l++;
				if(a[l].w < curMin)
				{
					curMin = a[l].w;
					curIdx = a[l].idx;
				}
			}
			if(curMin < a[r].w)
				ans[a[r].idx] = curIdx;
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}