#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
const int MAXN=100005;

ll n,s,to,rem;
int len;
ll cnt[MAXN];
int dep[MAXN];
ll check(int n,ll mid)
{
	ll sum=0;
	for(ll i=1,j=1,cur=0;;i++,j*=mid)
	{
		if(cur+j>=n){len=i;cnt[i]=n-cur;sum+=i*(n-cur);break;}
		cur+=j;sum+=i*j;
		cnt[i]=j;
	}
	return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>s;
    if(s<2*n-1 || s>n*(n+1)/2)return 0*printf("No\n");
    printf("Yes\n");
    int L=1,R=n-1,k=n,mid;
    while(L<=R)
    {
    	mid=(L+R)>>1;
    	if(check(n,mid)<=s)k=mid,R=mid-1;
    	else L=mid+1;
    }
    if(k==1)
    {
    	for(int i=2;i<=n;i++)
    		printf("%d ",i-1);
    	return 0;
    }
    check(n,k);
	for(int i=1;i<=len;i++)s-=i*cnt[i];
    to=len;
    if(s)
    {
	    for(int i=len;i;--i)
	    {
	    	bool flag=0;
	    	while(cnt[i]>1)
	    	{
	    		if(s>to+1-i){++to;s-=to-i;--cnt[i];}
	    		else {rem=s+i;--cnt[i];flag=1;break;}
	    	}
	    	if(flag)break;
	    }
	}
    int cur=1,ccc=0;
    dep[1]=1;
    for(int i=2;i<=len;i++)
    	for(int j=1;j<=cnt[i];j++)
    		dep[++cur]=i;
    for(int i=len+1;i<=to;i++)dep[++cur]=i;
    dep[++cur]=rem;
    sort(dep+1,dep+n+1);
    cur=1;
    for(int i=2;i<=n;i++)
    {
    	if(dep[i]!=dep[i-1])
    	{
    		while(dep[cur]<dep[i]-1)++cur;
    		ccc=0;
    	}
    	else if(ccc==k){ccc=0;++cur;}
    	++ccc;
    	printf("%d ",cur);
    }
    return 0;
}