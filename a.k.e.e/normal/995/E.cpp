#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define x first
#define y second
const int MAXN=205;

int u[2],MOD;
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=(ll)x*x%MOD)
		if(y&1)ans=(ll)ans*x%MOD;
	return ans;
}
unordered_map<int,int> m[2];
int a[2][MAXN*MAXN*MAXN],cnt[2];
vector<int> ans[2];

void work(int ty,int x,int from)
{
	if(m[ty].count(x))return;
	a[ty][++cnt[ty]]=x;
	m[ty][x]=from;
	if(m[ty^1].count(x))
	{
		for(int i=x;i>=0;i=m[0][i])
		{
			int t=m[0][i];
			if(t<0)break;
			if((i-t+MOD)%MOD==1)ans[0].push_back(1);
			else if((t-i+MOD)%MOD==1)ans[0].push_back(2);
			else ans[0].push_back(3);
		}
		for(int i=x;i>=0;i=m[1][i])
		{
			int t=m[1][i];
			if(t<0)break;
			if((i-t+MOD)%MOD==1)ans[1].push_back(2);
			else if((t-i+MOD)%MOD==1)ans[1].push_back(1);
			else ans[1].push_back(3);
		}
		printf("%d\n",ans[0].size()+ans[1].size());
		for(int i=ans[0].size()-1;i>=0;i--)printf("%d ",ans[0][i]);
		for(int i=0;i<ans[1].size();i++)printf("%d ",ans[1][i]);
		exit(0);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d%d",&u[0],&u[1],&MOD);
    m[0][u[0]]=-1;m[1][u[1]]=-1;
    a[0][0]=u[0];a[1][0]=u[1];
    for(int i=0;;i++)
    {
    	work(0,(a[0][i]+1)%MOD,a[0][i]);
    	work(0,(a[0][i]-1+MOD)%MOD,a[0][i]);
    	work(0,qmi(a[0][i],MOD-2),a[0][i]);
    	work(1,(a[1][i]+1)%MOD,a[1][i]);
    	work(1,(a[1][i]-1+MOD)%MOD,a[1][i]);
    	work(1,qmi(a[1][i],MOD-2),a[1][i]);
    }
    return 0;
}