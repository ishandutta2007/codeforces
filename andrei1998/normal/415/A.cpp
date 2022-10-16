#include <iostream>

using namespace std;

int v[105];
int main()
{
    int n,m;
    cin>>n>>m;

    while(m--)
    {
        int i;
        cin>>i;

        int init=i;
        while(1)
            if(!v[i])
                v[i++]=init;
            else
                break;
    }

    cout<<v[1];
    for(int i=2;i<=n;i++)
        cout<<' '<<v[i];
    cout<<'\n';

    return 0;
}