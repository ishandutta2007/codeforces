#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1005;

int n;
int a[N];
bool vis[N];

int get()
{
	for(int i = 0; i <= n; i++)
		vis[i] = 0;
	for(int i = 0; i < n; i++)
		vis[a[i]] = 1;
	for(int i = 0; i <= n; i++)
	{
		if(!vis[i])
			return i;
	}
}

bool check()
{
	for(int i = 1; i < n; i++)
		if(a[i] < a[i - 1])
			return 0;
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int idx = n;
		vector<int> v;
		while(!check())
		{
			int curMex = get();
			if(idx == curMex)
			{
				a[--idx] = curMex;
				v.push_back(idx);
			}
			else
			{
				a[curMex] = curMex;
				v.push_back(curMex);
			}
		}
		cout << v.size() << endl;
		for(auto &it:v)
			cout << it + 1 << " ";
		cout << endl;
	}
	return 0;
}