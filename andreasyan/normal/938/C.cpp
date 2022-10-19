#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int byn(int n,int x)
{
    int l=1,r=n;
    while((r-l)>4)
    {
        int m=(l+r)/2;
        if((n/m)*(n/m)<(n*n)-x)
            r=m;
        else
            l=m;
    }
    for(int i=l;i<=r;++i)
        if((n/i)*(n/i)==(n*n)-x)
            return i;
    return -1;
}
int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;++i)
    {
        int x;
        cin>>x;
        bool z=false;
        for(int n=1;n<=50000;++n)
        {
            if((n*n-x)>0)
            {
                int m=byn(n,x);
                if(m==-1)
                    continue;
                cout<<n<<' '<<m<<endl;
                z=true;
                break;
            }
        }
        if(!z)
            cout<<"-1"<<endl;
    }
    return 0;
}