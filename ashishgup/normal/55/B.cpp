#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;

int a, b, c, d;
char op[5];

int rec(int lvl, vector<int> rem)
{
	if(lvl==4)
		return rem[0];
	int ans=1e12;
	for(int i=0;i<rem.size();i++)
	{
		for(int j=i+1;j<rem.size();j++)
		{
			vector<int> cur;
			for(int k=0;k<rem.size();k++)
			{
				if(k==i || k==j)
					continue;
				cur.push_back(rem[k]);
			}
			if(op[lvl]=='+')
				cur.push_back(rem[i]+rem[j]);
			else
				cur.push_back(rem[i]*rem[j]);
			ans=min(ans, rec(lvl+1, cur));
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>a>>b>>c>>d;
	for(int i=1;i<=3;i++)
		cin>>op[i];
	vector<int> v={a, b, c, d};
	int ans=rec(1, v);
	cout<<ans;
	return 0;
}