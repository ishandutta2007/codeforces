#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

typedef long long ll;
const int MAXN=505;
const ll v[7]={1,1<<9,1ll<<18,1ll<<27,1ll<<36,1ll<<45,1ll<<54};

int n,m; 
char str[MAXN];
int a[MAXN][MAXN],o[MAXN][MAXN];
ll cnt[MAXN][MAXN][5];
inline bool checkodd(int x,int l,int r)
{
	int t=o[x][r]^o[x][l-1];
	return t==(t&-t);
}
inline bool checksame(int x,int y,int l,int r)
{
	for(int i=0;i<4;i++)
		if(cnt[x][r][i]-cnt[x][l-1][i]!=cnt[y][r][i]-cnt[y][l-1][i])
			return 0;
	return 1;
}

int p[MAXN];
ll tot=0,tot2=0;
int work(int l,int r)
{
	int mr=0,pos=0,ans=0;
	memset(p,0,sizeof(p));
	for(int i=1;i<=2*n-1;i++)
		if(!checkodd(i,l,r))p[i]=-1;
	p[0]=p[2*n]=-1;
	for(int i=1;i<=2*n-1;i++)
	{
		if(p[i]<0)
			{mr=pos=0;continue;}
		if(i<=mr)p[i]=min(p[pos*2-i],mr-i+1);
		else p[i]=1;
		//cout<<i+p[i]-1<<" "<<tot<<" ";
		for(;p[i-p[i]]>=0 && p[i+p[i]]>=0;++p[i])
		{
			++tot;
			if(!checksame(i-p[i],i+p[i],l,r))break;
		}
		if(i+p[i]-1>mr)mr=i+p[i]-1,pos=i;
		//cout<<tot<<" "<<mr<<endl;
		if(i&1)ans+=(p[i]+1)/2;
		else ans+=p[i]/2;
	}
	return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    memset(a,0,sizeof(a));
    memset(o,0,sizeof(o));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
    	scanf("%s",str+1);
    	for(int j=1;j<=m;j++)
    		a[i*2-1][j]=str[j]-'a'+1;
    }
    for(int i=1;i<=2*n-1;i++)
    	for(int j=1;j<=m;j++)
    	{
    		o[i][j]=o[i][j-1];
    		for(register int k=0;k<4;k++)
    			cnt[i][j][k]=cnt[i][j-1][k];
    		cnt[i][j][a[i][j]/7]+=v[a[i][j]%7];
    		if(a[i][j])o[i][j]^=(1<<(a[i][j]));
    	}
    ll ans=0;
    for(int l=1;l<=m;l++)
    	for(int r=l;r<=m;r++)
    		ans+=work(l,r);
    cout<<ans<<endl;
    return 0;
}