#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		string a,b;
		cin >> n >> a >> b;
		int cnta=0,cntb=0;
		for(auto t:a) cnta+=t=='1';
		for(auto t:b) cntb+=t=='1';
		if(cntb!=cnta&&cntb!=(1+(n-cnta)))
		{
			cout << "-1\n";
			continue;
		}
		int ans=1e9;
		if(cntb==cnta)
		{
			int qwq=0;
			for(int i=0;i<n;i++) qwq+=a[i]!=b[i];
			ans=min(ans,qwq);
		}
		if(cntb==(1+n-cnta))
		{
			int flag=0,qwq=1;
			for(int i=0;i<n;i++)
			{
				if(a[i]=='1'&&b[i]=='1')
				{
					flag=1;
					for(int j=0;j<n;j++) a[j]^=1;
					a[i]^=1;
					break;
				}
			}
			if(!flag)
			{
				for(int i=0;i<n;i++)
				{
					if(a[i]=='1')
					{
						flag=1;
						for(int j=0;j<n;j++) a[j]^=1;
						a[i]^=1;
						break;
					}
				}
			}
			if(flag==0);
			else
			{
				for(int i=0;i<n;i++)
					qwq+=a[i]!=b[i];
				ans=min(ans,qwq);
			}
		}
		if(ans>1e8) ans=-1;
		cout << ans << "\n";
	}
	return 0;
}