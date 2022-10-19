#include"bits/stdc++.h"
using namespace std;
int ans[10005];
int nn;
int main()
{
    for(int i=1;i<10005;i++)
    {
        if(i%3!=0&&i%10!=3)ans[nn++]=i;
    }
    //cout<<nn<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n-1]<<endl;
    }
    return 0;
}