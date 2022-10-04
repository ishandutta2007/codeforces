#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=300005;

int n;
struct Range
{
    int l,r,id;
    inline bool operator <(const Range &b)const
        {return l==b.l?r>b.r:l<b.l;}
}a[MAXN];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i].id=i;
        scanf("%d%d",&a[i].l,&a[i].r);
    }
    sort(a+1,a+n+1);
    int now=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].r<=now)
        {
            cout<<a[i].id<<" "<<a[i-1].id<<endl;
            return 0;
        }
        now=a[i].r;
    }
    cout<<"-1 -1"<<endl;
    return 0;
}