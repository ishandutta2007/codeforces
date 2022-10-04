#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAXN=200005,MOD=998244353;

int n,m;
char a[MAXN],b[MAXN];

int qmi(int x,int k)
{
	if(!k)return 1;
	int t=qmi(x,k>>1);
	if(k&1)return (ll)t*t%MOD*x%MOD;
	return (ll)t*t%MOD;
}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d%s%s",&n,&m,a+1,b+1);
    if(n<m)
    {
    	for(int i=m;i>m-n;--i)a[i]=a[i-m+n];
    	for(int i=m-n;i>0;--i)a[i]='0';
    }
    else if(n>m)
    	for(int i=1;i<=m;i++)a[i]=a[i+n-m];
    ll s=0,ans=0;
    for(int i=1;i<=m;i++)
    {
    	if(b[i]=='1')++s;
    	if(a[i]=='1')(ans+=s*qmi(2,m-i))%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}