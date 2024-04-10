#include <iostream>
#include <bitset>
#include <algorithm>
#include <bitset>

using namespace std;

struct elem
{
    int h;
    int m;

    elem(int a=0,int b=0)
    {
        h=a;
        m=b;
    }
}v[2][2015];
int l[2];

bool operator<(const elem &a,const elem &b)
{
    if(a.h<b.h)
        return 1;
    return 0;
}

bitset<2005> viz[2];

inline int best_poz(int sir,int putere)
{
    int i;

    int poz=0;
    for(i=1;i<=l[sir];i++)
        if(!viz[sir][i])
        {
            if(v[sir][i].h<=putere)
            if(v[sir][i].m>v[sir][poz].m)
            {
                poz=i;
            }
        }

    return poz;
}

int main()
{
    int n,x,i;
    cin>>n>>x;

    int a,b,c;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        v[a][++l[a]]=elem(b,c);
    }

    sort(v[0]+1,v[0]+l[0]+1);
    sort(v[1]+1,v[1]+l[1]+1);

    n=l[0];
    int ans=0;

///////////////////////////////////////////////////
    int h_curent=x;
    int ans_curent=0;
    i=0;

    int ultim=1;

    int k;
    while(1)
    {
        if(!ultim)
        {
            k=best_poz(1,h_curent);

            if(!k)
                break;
            viz[1][k]=1;

            ans_curent++;
            h_curent+=v[1][k].m;
            ultim=1;
        }
        else
        {
            k=best_poz(0,h_curent);
            if(!k)
                break;
            viz[0][k]=1;

            ans_curent++;
            h_curent+=v[0][k].m;
            ultim=0;
        }
    }
///////////////////////
    if(ans_curent>ans)
        ans=ans_curent;
////////////////

    h_curent=x;
    ans_curent=0;
    i=0;

    ultim=0;
    viz[0]&=0;
    viz[1]&=0;

    /////////////////////////////////////////////////
    while(1)
    {
        if(!ultim)
        {
            k=best_poz(1,h_curent);

            if(!k)
                break;
            viz[1][k]=1;

            ans_curent++;
            h_curent+=v[1][k].m;
            ultim=1;
        }
        else
        {
            k=best_poz(0,h_curent);
            if(!k)
                break;
            viz[0][k]=1;

            ans_curent++;
            h_curent+=v[0][k].m;
            ultim=0;
        }
    }
    ///////////////////////////////////////////////////

    if(ans_curent>ans)
        ans=ans_curent;

    cout<<ans<<'\n';
    return 0;
}