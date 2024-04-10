#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=21;
const int M=2e6;
char c[N][500000];
vector<int> ve[N][800010];
vector<pair<int,int> > pp[N];
int sum[N];
int dp[M],n; 
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int nn=4e5;
	rep(i,1,n)
	{ 
	  cin>>c[i];
	  int m=strlen(c[i]);
	  int now=0;
	  int gg=0;
	  rep(j,0,m-1)
	  {
	  	if (c[i][j]=='(') now++; else now--;
	  	ve[i][now+nn].push_back(j);
	  	if (now<gg)
	  	{
	  		gg=now;
	  		pp[i].push_back(make_pair(-now,j)); 
	  	}
	  }
	  sum[i]=now;
	}
	int ans=0;
	dp[0]=1;
	rep(i,0,(1<<n)-1)
	  if (dp[i]!=0)
	  {
	  	 int sum2=0;
	     rep(j,1,n)
		   if (((i>>(j-1))&1)) sum2+=sum[j];
	     rep(j,1,n)
		   if (!((i>>(j-1))&1))
		   {
		   		int now=i|(1<<(j-1));
				auto it=lower_bound(pp[j].begin(),pp[j].end(),make_pair(sum2+1,0));
				int h=1e9;
				if (it!=pp[j].end()) h=it->second; 
			    int kk=lower_bound(ve[j][-sum2+nn].begin(),ve[j][-sum2+nn].end(),h)-ve[j][-sum2+nn].begin();
			    ans=max(ans,dp[i]+kk);
			    if (h==1e9) dp[now]=max(dp[now],dp[i]+kk);
	       }
      }
    cout<<ans-1<<endl;
	return 0;
}