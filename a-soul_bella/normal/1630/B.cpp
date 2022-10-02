#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],cnt[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			a[i]=x;
			++cnt[x];
		}
		int mn=1e9,X=0,Y=0,now=1,sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=cnt[i];
			while(sum-cnt[now]-(n-sum+cnt[now])>=k)
			{
				sum-=cnt[now],++now;
			}
			if(sum-(n-sum)>=k)
			{
				if(i-now+1<=mn)
				{
					mn=i-now+1;
					X=now,Y=i;
				}
			}
		}
		cout << X << " " << Y << "\n";
		int qwq=0,lst=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=Y&&a[i]>=X) ++qwq;
			else --qwq;
			if(qwq==1&&k!=1)
			{
				--k;
				cout << lst+1 << " " << i << "\n"; 
				lst=i;
				qwq=0;
			}
		}
		cout << lst+1 << " " << n << "\n";
	}
	return 0;
}