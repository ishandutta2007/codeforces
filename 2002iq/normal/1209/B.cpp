#include <bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
	int n,ans=0;
	string s;
	cin >> n >> s;
	for (int i=0;i<n;i++)
	cin >> a[i] >> b[i];
	for (int i=0;i<1e5;i++)
	{
		int cnt=0;
		for (int j=0;j<n;j++)
		{
			if (i>=b[j] && (i-b[j])%a[j]==0)
			s[j]^=1;
			cnt+=(s[j]=='1');
		}
		ans=max(ans,cnt);
	}
	printf("%d",ans);
}