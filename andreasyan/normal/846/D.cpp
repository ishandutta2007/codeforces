#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=502;
struct ban
{
    int x,y,t;
};
bool operator<(const ban& a,const ban& b)
{
    return a.t<b.t;
}

int n,m,k,q;
ban a[N*N];

int c[N][N];

int cc[N][N];

bool stg(int x,int y)
{
    int sum=0;
    for(int i=max(1,x-k+1);i<=max(1,x-k+1)+k-1;++i)
        sum+=cc[i][y];
    for(int l=max(1,x-k+1);l<=n;++l)
    {
        int r=l+k-1;
        if(r>n)
            break;
        if(sum==k)
            return true;
        sum-=cc[l][y];
        sum+=cc[r+1][y];
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("search.in","r",stdin);
    //freopen("search.out","w",stdout);
    cin>>n>>m>>k>>q;
    for(int i=0;i<q;++i)
        cin>>a[i].x>>a[i].y>>a[i].t;
    int ans=-1;
    sort(a,a+q);
    for(int ii=0;ii<q;++ii)
    {
        int x=a[ii].x,y=a[ii].y,t=a[ii].t;
        c[x][y]=1;
        int sum=0;
        for(int j=max(1,y-k+1);j<=max(1,y-k+1)+k-1;++j)
            sum+=c[x][j];
        bool z=false;
        for(int l=max(1,y-k+1);l<=m;++l)
        {
            int r=l+k-1;
            if(r>m)
                break;
            if(sum==k)
            {
                if(!cc[x][l])
                {
                    cc[x][l]=1;
                    if(stg(x,l))
                    {
                        z=true;
                        break;
                    }
                }
            }
            sum-=c[x][l];
            sum+=c[x][r+1];
        }
        if(z)
        {
            ans=t;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}