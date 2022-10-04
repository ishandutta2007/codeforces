#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=1000005;

int n;
struct Node
{
    int fst,l;
    bool operator <(const Node &b)const
    {
        return fst<b.fst;
    }
}a[MAXN];

int main()
{
    int x,ans=0,tot=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x)
        {
            if(x<i)
            {
                a[++tot].fst=i-x;
                a[tot].l=x;
            }
            else if(i>1)
            {
                a[++tot].fst=1;
                a[tot].l=i-1;
            }
        }
    }
    sort(a+1,a+tot+1);
    /*printf("%d\n",tot);
    for(int i=1;i<=tot;i++)
        printf("%d %d\n",a[i].fst,a[i].l);*/
    x=1;
    for(int i=1;i<=tot;i++)
    {
        if(a[i].fst>x)
            ans+=a[i].fst-x;
        x=max(x,a[i].fst+a[i].l);
        //printf("%d\n",x);
    }
    ans+=n-x+1;
    printf("%d\n",ans);
    
    //system("pause");
    return 0;
}