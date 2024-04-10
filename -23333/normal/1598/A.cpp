#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
char s[2][N];
int n;
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		cin>>s[0]>>s[1];
		bool tt=0;
		rep(i,0,n-1)
		  if (s[0][i]=='1'&&s[1][i]=='1') tt=1;
		if (!tt) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}