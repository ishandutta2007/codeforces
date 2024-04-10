#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[1000005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d%s",&n,&m,s);
        int l=0,r=0,u=0,d=0,x=0,y=0;
        int sx,sy;
        for(int i=0;s[i];i++)
        {
            sx=1-d;
            sy=1-l;//cout<<"<<"<<l<<" "<<r<<" "<<u<<" "<<d<<" "<<x<<" "<<y<<" "<<sx<<" "<<sy<<endl;
            if(s[i]=='D')
            {
                x++;
                u=max(x,u);
            }
            if(s[i]=='U')
            {
                x--;
                d=min(x,d);
            }
            if(s[i]=='L')
            {
                y--;
                l=min(y,l);
            }
            if(s[i]=='R')
            {
                y++;
                r=max(y,r);
            }
            if(r-l>=m||u-d>=n)
            {
                cout<<sx<<" "<<sy<<endl;
                break;
            }
            if(s[i+1]==0)
            {
                sx=1-d;
                sy=1-l;
                cout<<sx<<" "<<sy<<endl;
            }
        }
    }
    return 0;
}