#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int n,i,v[100005],din[100005];
    bitset<100005> bun;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        if(i==1)
            bun[i]=0;
        else if(i==2)
            bun[i]=0;
        else if((v[i-2]+v[i-1])==v[i])
            bun[i]=1;
        else
            bun[i]=0;
    }

    int maxim=1;
    if(n>=2)
        maxim=2;

    din[1]=1;
    for(i=2;i<=n;i++)
    {
        if(bun[i])
        {
            din[i]=din[i-1]+1;
            if(din[i]>maxim)
                maxim=din[i];
        }
        else
            din[i]=2;
    }
    cout<<maxim<<'\n';

    return 0;
}