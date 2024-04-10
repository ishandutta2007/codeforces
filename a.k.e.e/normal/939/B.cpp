#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=100005;

ll n;
int m;
ll a[MAXN];

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>m;
    ll ms=(1ll<<60);
    int t;
    for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		if(n%a[i]<ms)
		{
			ms=n%a[i];
			t=i;
		}
	}
	cout<<t<<" "<<n/a[t]<<endl;
    return 0;
}