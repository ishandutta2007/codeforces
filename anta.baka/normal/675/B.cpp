#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int res=0;
    for(int i=1; i<=n; i++)
    {
        int x1=a+b+i-b-d,
            x2=a+b+i-d-c,
            x3=a+b+i-c-a;
        if(x1>0&&x2>0&&x3>0&&x1<=n&&x2<=n&&x3<=n)
            res++;
    }
    cout<<1ll*res*n;
    return 0;
}