
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e4;
const int mo=998244353;
const int M=(1<<24)+100;
char c[100][N];
ll g[M],f[M];
int n;
int num[100][100];
struct re{
	int a,b;
};
re num2[100][100];
int g1[100][100],g2[100][100];
bool cmp(re x,re y)
{
	return x.a<y.a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	rep(i,1,n)
	{ 
	  cin>>c[i];
	  int m=strlen(c[i]);
	  rep(j,0,m-1) num[i][c[i][j]-'a'+1]++;
    }
    rep(i,1,26)
    {
    	rep(j,1,n) num2[i][j].a=num[j][i],num2[i][j].b=j;
    	sort(num2[i]+1,num2[i]+n+1,cmp);
		int now=0;
		num2[i][0].a=-1;
		rep(j,1,n)
		{
			g1[i][j]=now;
			g2[i][j]=num2[i][j].a-num2[i][j-1].a;
			now|=(1<<(num2[i][j].b-1));
	    }
    }
    rep(i,1,(1<<n)-1) f[i]=1;
    int nn=(1<<n)-1;
   // cerr<<11<<endl;
	dep(i,26,1)
	{
		memcpy(g,f,sizeof(f));
		memset(f,0,sizeof(f));
		rep(j,0,(1<<n)-1)
		{
			rep(k,1,n)
			{
			    f[j]+=g[j&(nn^g1[i][k])]*g2[i][k];
		    }
		    f[j]%=mo;
		}
    }
    ll ans=0;
   // cerr<<1<<endl;
    rep(i,1,(1<<n)-1)
    {
      int cnt0=0,cnt1=0;
      rep(j,1,n)
        if ((i>>(j-1))&1) cnt0+=j,cnt1++;
      ans^=cnt0*cnt1*f[i];
      //cout<<i<<" "<<f[i]<<endl;
    }
    cout<<ans<<endl;
	return 0;
}