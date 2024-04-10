#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#endif

ll dp[2][105];
string s;

int main()
{
	IOS()
	ll ans=0;
	cin >> s;
	if(s[0]=='A')
	{
		dp[0][0]=1,dp[1][0]=0;
		for(int i=1;i<s.size();++i)
			if(s[i]=='A')
				if(s[i-1]=='B')
					dp[0][i]=dp[1][i-1],dp[1][i]=dp[0][i-1];
				else
					dp[0][i]=dp[0][i-1]+dp[1][i-1],dp[1][i]=0;
			else
				if(i+1<s.size()&&s[i+1]=='A')
					dp[0][i]=(dp[0][i-1]+dp[1][i-1]),dp[1][i]=dp[1][i-1];
				else
					dp[0][i]=0,dp[1][i]=dp[1][i-1];
		ans+=dp[0][s.size()-1]+dp[1][s.size()-1];
		if(s.back()=='B')
		{
			dp[0][0]=0,dp[1][0]=1;
			for(int i=1;i+1<s.size();++i)
				if(s[i]=='A')
					if(s[i-1]=='B')
						dp[0][i]=dp[1][i-1],dp[1][i]=dp[0][i-1];
					else
						dp[0][i]=dp[0][i-1]+dp[1][i-1],dp[1][i]=0;
				else
					if(i+1<s.size()&&s[i+1]=='A')
						dp[0][i]=(dp[0][i-1]+dp[1][i-1]),dp[1][i]=dp[1][i-1];
					else
						dp[0][i]=0,dp[1][i]=dp[1][i-1];
			ans+=dp[0][s.size()-2]+dp[1][s.size()-2];
		}
	}
	else
	{
		dp[0][0]=0,dp[1][0]=1;
		for(int i=1;i<s.size();++i)
			if(s[i]=='A')
				if(s[i-1]=='B')
					dp[0][i]=dp[1][i-1],dp[1][i]=dp[0][i-1];
				else
					dp[0][i]=dp[0][i-1]+dp[1][i-1],dp[1][i]=0;
			else
				if(i+1<s.size()&&s[i+1]=='A')
					dp[0][i]=(dp[0][i-1]+dp[1][i-1]),dp[1][i]=dp[1][i-1];
				else
					dp[0][i]=0,dp[1][i]=dp[1][i-1];
		ans+=dp[1][s.size()-1];
		if(s[1]=='A')
		{
			dp[0][0]=1,dp[1][0]=0;
			for(int i=1;i<s.size();++i)
				if(s[i]=='A')
					if(s[i-1]=='B')
						dp[0][i]=dp[1][i-1],dp[1][i]=dp[0][i-1];
					else
						dp[0][i]=dp[0][i-1]+dp[1][i-1],dp[1][i]=0;
				else
					if(i+1<s.size()&&s[i+1]=='A')
						dp[0][i]=(dp[0][i-1]+dp[1][i-1]),dp[1][i]=dp[1][i-1];
					else
						dp[0][i]=0,dp[1][i]=dp[1][i-1];
			ans+=dp[0][s.size()-1]+dp[1][s.size()-1];
		}
	}
	cout << ans << "\n";
}