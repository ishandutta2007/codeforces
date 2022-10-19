#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=500005;

int n;
int a[N];

int main()
{
	//freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<a[0]<<endl;
        return 0;
    }
    bool z=false,zz=false;
    long long ans=0;
    int minu=a[0];
    int maxu=a[0];
    for(int i=0;i<n;++i)
    {
        if(a[i]<=0)
            z=true;
        if(a[i]>=0)
            zz=true;
        minu=min(minu,a[i]);
        maxu=max(maxu,a[i]);
        ans+=abs(a[i]);
    }
    if(z && zz)
        cout<<ans<<endl;
    else
    {
        if(zz)
            cout<<ans-minu-minu<<endl;
        if(z)
            cout<<ans+maxu+maxu<<endl;
    }
	return 0;
}