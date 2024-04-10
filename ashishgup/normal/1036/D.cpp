#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, m, ans=0;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	int idx1=1, idx2=1, s1=0, s2=0;
	while(idx1<=n&&idx2<=m)
	{
		s1+=a[idx1];
		s2+=b[idx2];
		idx1++;
		idx2++;
		while(s1!=s2)
		{
			if(s1<s2)
			{
				if(idx1<=n)
					s1+=a[idx1++];
				else
					break;
			}
			else
			{
				if(idx2<=m)
					s2+=b[idx2++];
				else
					break;
			}
		}
		if(s1!=s2)
		{
			cout<<"-1";
			return 0;
		}
		ans++;
	}
	if(idx1<=n || idx2<=m)
	{
		cout<<"-1";
		return 0;
	}
	cout<<ans;
	return 0;
}