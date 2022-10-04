#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define x first
#define y second
void chkmax(int &x,int y){x<y?x=y:0;}
void chkmin(int &x,int y){x>y?x=y:0;}
const int MAXN=1000005;

int n,w,len;
ll a[MAXN],ans[MAXN],pre[MAXN],suf[MAXN],pre_tag[MAXN],suf_tag[MAXN];
int q[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&len);
    	for(int j=1;j<=len;j++)scanf("%lld",&a[j]);
    	pre[0]=suf[len+1]=0;
    	for(int j=1;j<=len;j++)pre[j]=max(pre[j-1],a[j]);
    	for(int j=len;j;j--)suf[j]=max(suf[j+1],a[j]);
    	if(2*len>=w)
    	{
    		int front=1,rear=0;
    		for(int j=1;j<=w-len;j++)ans[j]+=pre[j];
    		for(int j=len+1;j<=w;j++)ans[j]+=suf[j-(w-len)];
    		for(int j=1;j<=len;j++)
    		{
    			if(front<=rear && j-q[front]>=w-len+1)++front;
    			while(front<=rear && a[j]>=a[q[rear]])--rear;
    			q[++rear]=j;
    			if(j>=w-len+1)ans[j]+=a[q[front]];
    		}
    	}
    	else
    	{
    		for(int j=1;j<=len;j++)ans[j]+=pre[j];
    		for(int j=w-len+1;j<=w;j++)ans[j]+=suf[j-(w-len)];
    		pre_tag[len+1]+=pre[len];
    		suf_tag[w-len]+=suf[1];
    	}
    }
    for(int i=1;i<=w/2;i++)ans[i]+=(pre_tag[i]+=pre_tag[i-1]);
    for(int i=w;i>w/2;i--)ans[i]+=(suf_tag[i]+=suf_tag[i+1]);
	for(int i=1;i<=w;i++)printf("%I64d ",ans[i]);
    return 0;
}