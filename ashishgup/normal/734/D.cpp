#include <bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(false);
using namespace std;

int main()
{
    IOS
    ll no;
    cin>>no;
    ll xo,yo;
    cin>>xo>>yo;
    char n=' ',ne=' ',e=' ',se=' ',s=' ',sw=' ',w=' ',nw=' ';
    ll nd=2000000001,ned=2000000001,ed=2000000001,sed=2000000001,sd=2000000001,swd=2000000001,wd=2000000001,nwd=200000000;
    for(int i=0;i<no;i++)
    {
        char ch;
        ll x,y;
        cin>>ch>>x>>y;
        if(x==xo)
        {
            if(y>yo)
            {
                ll dist=y-yo;
                if(dist<nd)
                {
                    n=ch;
                    nd=dist;
                }
            }
            else
            {
                ll dist=yo-y;
                if(dist<sd)
                {
                    s=ch;
                    sd=dist;
                }
            }
        }
        else if(y==yo)
        {
            if(x>xo)
            {
                ll dist=x-xo;
                if(dist<ed)
                {
                    e=ch;
                    ed=dist;
                }
            }
            else
            {
                ll dist=xo-x;
                if(dist<wd)
                {
                    w=ch;
                    wd=dist;
                }
            }
        }
        else
        {
            ll distx=x-xo;
            ll disty=y-yo;
            if(abs(distx)!=abs(disty))
            {
                continue;
            }
            if(distx>0&&disty>0)
            {
                if(distx<ned)
                {
                    ne=ch;
                    ned=distx;
                }
            }
            else if(distx<0&&disty<0)
            {
                if(abs(distx)<swd)
                {
                    sw=ch;
                    swd=abs(distx);
                }
            }
            else if(distx>0&&disty<0)
            {
                if(distx<sed)
                {
                    se=ch;
                    sed=distx;
                }
            }
            else
            {
                if(disty<nwd)
                {
                    nw=ch;
                    nwd=disty;
                }
            }
        }
    }
    bool ch=false;
    if(n=='Q'||n=='R')
    {
        ch=true;
    }
    if(s=='Q'||s=='R')
    {
        ch=true;
    }
    if(e=='Q'||e=='R')
    {
        ch=true;
    }
    if(w=='Q'||w=='R')
    {
        ch=true;
    }
    if(nw=='Q'||nw=='B')
    {
        ch=true;
    }
    if(ne=='Q'||ne=='B')
    {
        ch=true;
    }
    if(sw=='Q'||sw=='B')
    {
        ch=true;
    }
    if(se=='Q'||se=='B')
    {
        ch=true;
    }
    if(ch)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}