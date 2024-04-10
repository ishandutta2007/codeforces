#include <iostream>

using namespace std;

int main()
{
    int n,t=0,x,m=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        t=t+x;
        m=max(m,x);
    }
    t=((t*2)/n)+1;
    if (t<m) t=m;
    cout<<t;
    return 0;
}