#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
const int N=202;
struct ban
{
    int l,r;
};

int n,m;
ban a[N];
bool c[N];
bool stg()
{
    for(int i=1;i<=n;++i)
        if(!c[i])
            return false;
    return true;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int ans=0;
        cin>>n>>m;
        for(int i=0;i<m;++i)
        {
            cin>>a[i].l;
            a[i].r=a[i].l;
        }
        for(int i=1;i<=n;++i)
            c[i]=false;
        while(!stg())
        {
            for(int i=0;i<m;++i)
            {
                if(a[i].l>=1)
                    c[a[i].l]=true;
                if(a[i].r<=n)
                    c[a[i].r]=true;
                ++a[i].r;
                --a[i].l;
            }
            ++ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}