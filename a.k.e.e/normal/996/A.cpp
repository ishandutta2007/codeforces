#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    ll n,ans=0;
    cin>>n;
    int p[5]={100,20,10,5,1};
    for(int i=0;i<5;i++)
    	ans+=n/p[i],n%=p[i];
    cout<<ans<<endl;
    return 0;
}