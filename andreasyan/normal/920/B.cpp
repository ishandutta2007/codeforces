#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
struct ban
{
    int l,r,i;
};
bool operator<(const ban& a,const ban& b)
{
    if(a.l<b.l)
        return true;
    if(a.l>b.l)
        return false;
    return a.i<b.i;
}
const int N=1003;

int n;
ban a[N];
int ans[N];
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].i=i;
        }
        sort(a,a+n);
        int t=1;
        for(int i=0;i<n;++i)
        {
            if(a[i].r<t)
            {
                ans[a[i].i]=0;
                continue;
            }
            if(a[i].l>t)
            {
                t=a[i].l;
            }
            ans[a[i].i]=t;
            ++t;
        }
        for(int i=0;i<n;++i)
            printf("%d ",ans[i]);
        cout<<endl;
    }
}