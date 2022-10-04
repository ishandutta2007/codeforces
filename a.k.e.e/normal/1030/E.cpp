#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int n,a[MAXN],s[MAXN];

int main()
{
    ll x;
    int sum,s2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	cin>>x;
    	for(;x;x>>=1)
    		if(x&1)++a[i];
    	//cout<<a[i]<<" ";
    }
    //cout<<endl;
    int cnt=0,now=0;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
    	s[i]=s[i-1]+a[i];
    	now^=(a[i]&1);
    	if(now)ans+=cnt;
    	else ans+=i-cnt;
    	cnt+=now;
    }
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    	for(int l=i;l && (a[l]<a[i] || l==i) && s[i]-s[l-1]<2*a[i];--l)
    		for(int r=i;r<=n && (a[r]<a[i] || r==i) && s[r]-s[l-1]<2*a[i];++r)
    			if( !((s[r]-s[l-1])&1) && s[r]-s[l-1]<2*a[i] )
    				--ans;
    cout<<ans<<endl;
    return 0;
}