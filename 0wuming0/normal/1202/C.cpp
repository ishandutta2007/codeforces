#include<bits/stdc++.h>
#define ll long long
using namespace std;
string ss;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>ss;
        int n=ss.size();
        int w,a,s,d;
        w=a=s=d=0;
        int x,y;
        x=y=0;
        int jw=1,ja=1,js=1,jd=1;
        for(int i=0;i<n;i++)
        {
            switch(ss[i])
            {
                case'W':x++;if(w==x)js=0;if(w<x)w=x,jw=1,js=0;break;
                case'A':y--;if(a==y)jd=0;if(a>y)a=y,ja=1,jd=0;break;
                case'S':x--;if(s==x)jw=0;if(s>x)s=x,js=1,jw=0;break;
                case'D':y++;if(d==y)ja=0;if(d<y)d=y,jd=1,ja=0;break;
            }
        }
        int dx=0,dy=0;
        x=w-s+1;
        y=d-a+1;
        if(x>2)dx=jw+js;
        if(y>2)dy=jd+ja;
        printf("%lld\n",min((x-dx)*(ll)y,(ll)x*(y-dy)));
    }
    return 0;
}