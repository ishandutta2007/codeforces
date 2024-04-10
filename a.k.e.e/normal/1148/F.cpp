#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;
#define mask first
#define val second
const int MAXN=300005;

inline int sig(ll x){return x>0?1:-1;}
inline int calc(ll x)
{
	int res=1;
	for(int i=0;i<63;i++)
		if(x&(1ll<<i))res=-res;
	return res;
}

int n;
pii a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    ll rea=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%I64d",&a[i].val,&a[i].mask);
    	rea+=a[i].val;
    }
    sort(a+1,a+n+1);
    ll cur=0,bit=1,sum=0;
    for(int i=1;i<=n;i++)
    {
//cout<<a[i].mask<<" "<<a[i].val<<" "<<cur<<" "<<bit<<" "<<sum<<endl;
    	while(a[i].mask>=bit)
		{
			if(sig(sum)==sig(rea))cur|=(bit>>1);
			bit<<=1;sum=0;
		}
    	sum+=calc(a[i].mask&cur)*a[i].val;
    }
	if(sig(sum)==sig(rea))cur|=(bit>>1);
    cout<<cur<<endl;
    return 0;
}