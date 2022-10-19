#include"bits/stdc++.h"
using namespace std;
int a[105],b[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if(l==r&&r!=1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if((r>>1)-((l-1)>>1)>=r-l+1-k)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}