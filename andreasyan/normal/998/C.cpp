#include <bits/stdc++.h>
using namespace std;
const int N=300003;
const long long INF=999999999999999999;

int n,x,y;
char a[N];

long long ans=INF;

void solv(long long zro)
{
    long long yans=zro;
    for(int i=0;i<n;++i)
    {
        if(a[i]=='0' && (!i || a[i]!=a[i-1]))
            yans+=y;
    }
    ans=min(ans,yans);
    yans=zro;
    int k;
    for(int i=n-1;i>=0;--i)
        if(a[i]=='0')
        {
            k=i;
            break;
        }
    k++;
    for(int i=0;i<n;++i)
    {
        if(i>0 && a[i]=='1' && a[i-1]=='0' && i!=k)
            yans+=x;
    }
    yans+=y;
    ans=min(ans,yans);
}

int main()
{
    cin>>n>>x>>y;
    cin>>a;
    solv(0);
    reverse(a,a+n);
    solv(0);
    cout<<ans<<endl;
    return 0;
}