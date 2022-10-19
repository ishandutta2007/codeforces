#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int ans=r%l;
        if(r%2==0)r--;
        if(l<=r/2+1)ans=r/2;
        cout<<ans<<endl;
    }
    return 0;
}