#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        n=max(n,m)-min(n,m);
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }
        int now=0;
        for(int i=1;;i++)
        {
            now+=i;
            if(now>=n&&(now-n)%2==0)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}