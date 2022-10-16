#include <iostream>

using namespace std;

bool k_good(int x,int k)
{
    bool cifre[10];
    int i;
    for(i=0;i<10;i++)
        cifre[i]=0;
    while(x)
    {
        cifre[x%10]=1;
        x/=10;
    }

    bool bun=true;
    for(i=0;i<=k;i++)
        if(cifre[i]==0)
        {
            bun=false;
            break;
        }
    return bun;
}

int main()
{
    int n,k,i,y,p=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>y;
        if(k_good(y,k))
            p++;
    }
    cout<<p<<'\n';

    return 0;
}