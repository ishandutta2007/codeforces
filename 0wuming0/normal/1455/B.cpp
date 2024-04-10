#include"bits/stdc++.h"
using namespace std;
int so[1005005];
int main()
{
    for(int i=1;i*(i+1)/2<=1005000;i++)
    {
        so[i*(i+1)/2]=i;
    }
    int now=0;
    for(int i=1;i<=1005000;i++)
    {
        if(so[i])now=so[i];
        else if(so[i+1])so[i]=so[i+1]+1;
        else
        {
            so[i]=now+1;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<so[n]<<endl;
    }
    return 0;
}