#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=5005;
struct ban
{
    int l,r,h;
};

int n,z;
char a[N];
ban t[N*4];
/*ban mer(ban ll,ban rr)
{
    ban res;
    int minu=min(ll.r,rr.l);
    ll.r-=minu;
    rr.l-=minu;
    minu=min(ll.h,rr.l);
    ll.h-=minu;
    rr.l-=minu;
    minu=min(ll.r,rr.h);
    ll.r-=minu;
    rr.h-=minu;
    minu=min(ll.h,rr.h);
    ll.h-=minu;
    rr.h-=minu;
    res.h=ll.h+rr.h;
    res.l=ll.l+rr.l;
    res.r=ll.r+rr.r;
    return res;
}
void bul(int tl,int tr,int pos)
{
    if(tl==tr)
    {
        if(a[tl]=='(')
            t[pos].r++;
        else if(a[tl]==')')
            t[pos].l++;
        else
            t[pos].h++;
        return;
    }
    int m=(tl+tr)/2;
    bul(tl,m,pos*2);
    bul(m+1,tr,pos*2+1);
    t[pos]=mer(t[pos*2],t[pos*2+1]);
}
void ubd(int tl,int tr,int x,int pos)
{
    if(tl==tr)
    {
        t[pos].l=0;
        t[pos].r=0;
        if(a[x]=='(')
            t[pos].r++;
        else
            t[pos].l++;
        return;
    }
    int m=(tl+tr)/2;
    if(x<=m)
        ubd(tl,m,x,pos*2);
    else
        ubd(m+1,tr,x,pos*2+1);
    t[pos]=mer(t[pos*2],t[pos*2+1]);
}
ban qry(int tl,int tr,int l,int r,int pos)
{
    if(tl==l && tr==r)
        return t[pos];
    int m=(tl+tr)/2;
    if(r<=m)
        return qry(tl,m,l,r,pos*2);
    else if(l>m)
        return qry(m+1,tr,l,r,pos*2+1);
    else
        return mer(qry(tl,m,l,m,pos*2),qry(m+1,tr,m+1,r,pos*2+1));
}*/
int main()
{
    cin>>a;
    n=strlen(a);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int h=0,l=0,r=0;
        int rl=0,rh=0,hl=0,hh=0;
        for(int j=i;j<n;++j)
        {
            if(a[j]=='(')
            {
                ++r;
            }
            else if(a[j]==')')
            {
                if(r)
                {
                    --r;
                    ++rl;
                    if(!l && !r && !h)
                        ++ans;
                    continue;
                }
                if(h)
                {
                    --h;
                    ++hl;
                    if(!l && !r && !h)
                        ++ans;
                    continue;
                }
                if(rh)
                {
                    --rh;
                    ++rl;
                    ++h;
                    continue;
                }
                if(hh)
                {
                    --hh;
                    ++hl;
                    ++h;
                    continue;
                }
                ++l;
            }
            else
            {
                if(r)
                {
                    --r;
                    ++rh;
                    if(!l && !r && !h)
                        ++ans;
                    continue;
                }
                if(h)
                {
                    --h;
                    ++hh;
                    if(!l && !r && !h)
                        ++ans;
                    continue;
                }
                ++h;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}