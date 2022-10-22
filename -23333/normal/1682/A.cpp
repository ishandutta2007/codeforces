#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=3e5;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		cin>>(s+1);
		int k=(n+1)/2,i,j;
		for (i=k;i>=1;i--)
		  if (s[i]!=s[k]) break;
		for (j=k;j<=n;j++)
		  if (s[j]!=s[k]) break;
		cout<<j-i-1<<endl;
	}
	return 0;
}