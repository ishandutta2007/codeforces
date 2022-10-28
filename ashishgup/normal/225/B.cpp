#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int s, k;
int f[N];

int32_t main()
{
	IOS;
	cin>>s>>k;
	f[0]=1;
	int last=0;
	for(int i=1;;i++)
	{
		for(int j=max(0LL, i-k);j<i;j++)
		{
			f[i]+=f[j];
			if(f[i]>s)
			{
				last=i-1;
				break;
			}
		}
		if(f[i]>s)
			break;
	}
	vector<int> ans;
	for(int i=last;i>=0;i--)
	{
		if(s>=f[i])
		{
			s-=f[i];
			ans.push_back(f[i]);
		}
	}
	ans.push_back(0);
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}