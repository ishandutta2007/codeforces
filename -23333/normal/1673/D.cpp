#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
int dp[N];
const int mo=1e9+7;
int gcd(int x,int y)
{
	if (!y) return x;
	return gcd(y,x%y);
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		ll a,b,c,A,B,C;
		cin>>a>>b>>c;
		cin>>A>>B>>C;
		bool tt=1;
		if (A-a>=0&&(A-a)%b==0&&B%b==0&&(A+(C-1)*B-a)/b<=c-1)
		{
			if ((A-a)<B) tt=0;
			if ((a+(c-1)*b)-(A+(C-1)*B)<B) tt=0;
		    if (!tt)
		    {
		    	cout<<-1<<endl;
		    } else
		    {
		    	vector<int> ve;
		    	for (int i=1;i<=sqrt(B);i++)
				   if (B%i==0)
				   {
				   	  ve.push_back(i);
				   	  if (i*i!=B) ve.push_back(B/i); 
				   }
				ll ans=0;
				for (auto v:ve)
				  if (v*b/gcd(v,b)==B)
				  {
				  	(ans+=1ll*(B/v)*(B/v))%=mo;
				  }
				cout<<ans<<endl;
		    }
		} else cout<<0<<endl;
	}
	return 0;
}
/*
1
-9 3 11
0 6 3
*/