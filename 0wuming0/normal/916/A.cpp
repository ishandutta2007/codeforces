#include"bits/stdc++.h"
using namespace std;
int main()
{
    int h,m,x;
    cin>>x>>h>>m;
    int ans=0;
    while(h%10!=7&&m%10!=7)
    {
        m-=x;
        if(m<0)m+=60,h--;
        if(h<0)h+=24;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}