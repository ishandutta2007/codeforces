#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) (int(x.size()))
const int inf=1e9;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}

const int N=100005;
int T;
int n;
int a[N];
void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++)
        if(a[i]%2==0) cnt0++;
        else cnt1++;
    if(n%2==0&&cnt0!=cnt1)
    {
        printf("-1\n");
        return;
    }
    long long ans=1e18;
    if(n%2==0||(n%2==1&&cnt0+1==cnt1))
    {
        int pre1=0,pre0=0;
        long long ans1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==0) pre0++,ans1+=abs(pre0-pre1);
            else pre1++;
        }
        ans=min(ans,ans1);
    }
    if(n%2==0||(n%2==1&&cnt0==cnt1+1))
    {
        int pre1=0,pre0=0;
        long long ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==0) pre0++,ans2+=abs(pre0-1-pre1);
            else pre1++;
        }
        ans=min(ans,ans2);
    }
    if(ans>=1e18) printf("-1\n");
    else printf("%lld\n",ans);
    return;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0; 
}