#include<iostream>
#include<fstream>
using namespace std;
int n,m,a[100001],q,sum;
int used[1000001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        used[a[i]+sum]=i;
        used[1+sum]=i;
        sum+=a[i];
    }
    cin>>m;
    for(int j=1;j<=m;j++)
    {
        cin>>q;
        if(used[q])
        {
            cout<<used[q]<<endl;
            continue;
        }
        for(int k=1;k<=n;k++)
        {
            if(used[q+k])
            {
                cout<<used[q+k]<<endl;
                break;
            }
            if(used[q-k])
            {
                cout<<used[q-k]<<endl;
                break;
            }
        }
    }
    return 0;
}