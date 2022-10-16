#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char sir[1005];
    int n,m,i,j,v[1005],ps,pb;

    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin.get();
        cin.get(sir,1005);

        for(j=0;j<m;j++)
            if(sir[j]=='G')
                ps=j;
            else if(sir[j]=='S')
                pb=j;

        if(ps>pb)
        {
            cout<<"-1\n";
            return 0;
        }

        v[i]=pb-ps;
    }

    sort(v+1,v+n+1);
    int pasi=0;

    for(i=1;i<=n;i++)
    {
        if(v[i])
        {
            pasi++;
            for(j=i+1;j<=n;j++)
                v[j]-=v[i];

            v[i]=0;
        }
    }

    cout<<pasi<<'\n';


    return 0;
}