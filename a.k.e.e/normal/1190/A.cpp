#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

ll n,k;int m;
ll p[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){cin>>p[i];--p[i];}
    ll rem=0,las=1,temp=0;
	ll ans=1;
    for(int i=1;i<=m;i++)
    {
    	if((p[i]-rem)/k==(p[las]-rem)/k)++temp;
    	else rem+=temp,las=i,temp=1,++ans;
    }
    cout<<ans<<endl;
    return 0;
}