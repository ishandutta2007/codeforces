#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=1000006;

int n,m,k;
vector<pair<int,int> > a[N],b[N];

long long p[N],s[N];

int q;
long long sum;
int g[N];
void av(int i,int c)
{
    sum-=g[i];
    if(g[i]==0)
    {
        q++;
        g[i]=c;
    }
    else
    {
        g[i]=min(g[i],c);
    }
    sum+=g[i];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin>>n>>m>>k;
    while(m--)
    {
        int d,f,t,c;
        cin>>d>>f>>t>>c;
        if(t==0)
            a[d].push_back(m_p(f,c));
        if(f==0)
            b[d].push_back(m_p(t,c));
    }
    for(int i=0;i<=1000002;++i)
    {
        for(int j=0;j<a[i].size();++j)
            av(a[i][j].first,a[i][j].second);
        if(q<n)
            p[i]=-1;
        else
            p[i]=sum;
    }
    q=0;
    sum=0;
    memset(g,0,sizeof g);
    for(int i=1000002;i>=0;--i)
    {
        for(int j=0;j<b[i].size();++j)
            av(b[i][j].first,b[i][j].second);
        if(q<n)
            s[i]=-1;
        else
            s[i]=sum;
    }
    long long ans=-1;
    for(int l=1;l<=1000000-k+1;++l)
    {
        int r=l+k-1;
        if(p[l-1]==-1 || s[r+1]==-1)
            continue;
        if(ans==-1)
            ans=p[l-1]+s[r+1];
        else
            ans=min(ans,p[l-1]+s[r+1]);
    }
    cout<<ans<<endl;
    return 0;
}