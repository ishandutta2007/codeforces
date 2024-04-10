#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
char s[2][N];
int a[N][6];
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
		rep(i,1,n)
		  rep(j,1,5) cin>>a[i][j];
		bool tt=0;
		rep(i,1,5)
		  rep(j,1,5)
		    if (i!=j)
		    {
		    	int cnt1=0,cnt2=0,cnt3=0;
		    	rep(k,1,n)
		    	{ 
		    	  if (a[k][i]&&a[k][j]) cnt3++;
				  else if (a[k][i]) cnt1++;
				  else if (a[k][j]) cnt2++;
			    }
			    if (cnt1+cnt2+cnt3==n&&cnt1+cnt3>=n/2&&cnt2+cnt3>=n/2) tt=1; 
		    }
		if(tt) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}