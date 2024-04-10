#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=105;

int n,a[MAXN];
bool d[MAXN],f[MAXN];

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    d[0]=true;
    for(int i=1;i<=n;i++)
    {
		d[i]=f[i]=false;
    	if(!(a[i]&1))continue;
    	for(int j=1;j<=i;j+=2)
    	{
    		if(f[i-j] && (a[i-j+1]&1))d[i]=true;
    		if(d[i-j] && (a[i-j+1]&1))f[i]=true;
    	}
    }
    if(f[n])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}