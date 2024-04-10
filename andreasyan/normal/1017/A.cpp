#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct ban
{
    int i;
    int x;
};
bool operator<(const ban& a,const ban& b)
{
    if(a.x>b.x)
        return true;
    if(a.x<b.x)
        return false;
    return a.i<b.i;
}

int n;
ban a[N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("hall.in","r",stdin);
    //freopen("hall.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        a[i].i=i;
        a[i].x=0;
        for(int j=0;j<4;++j)
        {
            int y;
            cin>>y;
            a[i].x+=y;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        if(a[i].i==1)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}