#include <iostream>

using namespace std;
int n,a,b,c,t;
int main()
{
    cin>>n>>a>>b>>c>>t;
    int kq=0,x;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        kq=kq+(c-b)*(t-x);
    }
    if (kq>0) cout<<kq+n*a; else cout<<n*a;
    return 0;
}