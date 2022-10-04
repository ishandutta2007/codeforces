#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN=5005;

int n,a[MAXN];

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    	if(a[a[a[i]]]==i)
    	{
    		cout<<"YES"<<endl;
    		return 0;
    	}
    cout<<"NO"<<endl;
    return 0;
}