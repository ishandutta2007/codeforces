#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],b[200005],del[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) del[i]=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		int nowa=n,nowb=n,flag=1;
		while(nowb||nowa)
		{
			if(a[nowa]!=b[nowb])
			{
				if(del[a[nowa]])
				{
					--del[a[nowa]];
					--nowa;
					continue;
				}
				else
				{
					flag=0;
					break;
				}
			}
			int pa=nowa,pb=nowb;
			int cnta=0,cntb=0;
			while(a[pa]==a[nowa]) --nowa,++cnta;
			while(b[pb]==b[nowb]) --nowb,++cntb;
			while(cnta>cntb&&del[a[pa]]) --cnta,--del[a[pa]];
			if(cnta<=cntb) del[a[pa]]+=cntb-cnta;
			else
			{
				flag=0;
				break;
			}
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}