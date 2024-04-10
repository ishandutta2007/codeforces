#include <bits/stdc++.h>
using namespace std;
int ans[10005];
inline int query(int x)
{
	cout << "? " << x << endl;
	int k;
	cin >> k;
	return k;
}
signed main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		memset(ans,0,sizeof ans);
		for(int i=1;i<=n;i++)
		{
			if(!ans[i])
			{
				vector <int> v;
				int qwq=query(i),x;
				v.push_back(qwq);
				while((x=query(i))!=qwq)
					v.push_back(x);
				for(int i=1;i<v.size();i++)
					ans[v[i-1]]=v[i];
				ans[v.back()]=qwq;
			}
		}
		cout << "! ";
		for(int i=1;i<=n;i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}