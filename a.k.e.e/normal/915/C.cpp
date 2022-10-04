#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;
const int MAXN=21,INF=1<<30;

int a[MAXN],len;
ll f[MAXN];
bool vis[MAXN];

int find(int x)
{
	int cnt=0;
	for(int i=1;i<=len;i++)
		if(!vis[i])
		{
			cnt++;
			if(cnt==x)return i;
		}
}

ll encode(ll x)
{
	ll ans=0;
	int t;
	memset(vis,0,sizeof(vis));
	for(int i=len-1;i>=0;i--)
	{
		t=find(x/f[i]+1);
		vis[t]=true;
		ans=ans*10+a[t];
		x%=f[i];
	}
	return ans;
}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    ll num,b;
    int ocnt=0;
    cin>>num>>b;
    len=0;
    while(num)
    {
    	a[++len]=num%10;
    	num/=10;
    	if(!a[len])ocnt++;
    }
    sort(a+1,a+len+1);
    ll l,r,mid,ans=0;
    f[0]=1;
    for(int i=1;i<=len;i++)
		f[i]=f[i-1]*i;
	l=0;
	r=f[len]-1;
    while(l<=r)
    {
    	mid=(l+r)>>1;
    	if(encode(mid)<=b)
    	{
    		ans=max(ans,mid);
    		l=mid+1;
    	}
    	else r=mid-1;
    }
    cout<<encode(ans)<<endl;
    return 0;
}