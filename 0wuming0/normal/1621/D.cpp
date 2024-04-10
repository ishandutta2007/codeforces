#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll c[505][505];
int vis[505][505];
void add(multimap<ll,pair<int,int> >&st,int i,int j,ll dis)
{
    st.insert(make_pair(dis+c[i][j],make_pair(i,j)));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n*=2;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        {
            scanf("%lld",&c[i][j]);
            vis[i][j]=0;
        }
        ll ans=0;
        for(int i=0;i<=n/2;i++)for(int j=0;j<=n/2;j++)vis[i][j]=1;
        for(int i=n/2+1;i<=n;i++)for(int j=n/2+1;j<=n;j++)
        {
            vis[i][j]=1;
            ans+=c[i][j];
        }
        ll kkk=2e9;
        kkk=min(kkk,c[1][n]);kkk=min(kkk,c[n/2][n]);kkk=min(kkk,c[1][n/2+1]);kkk=min(kkk,c[n/2][n/2+1]);
        kkk=min(kkk,c[n][1]);kkk=min(kkk,c[n][n/2]);kkk=min(kkk,c[n/2+1][1]);kkk=min(kkk,c[n/2+1][n/2]);
        cout<<ans+kkk<<endl;
        continue;
        multimap<ll,pair<int,int> >st;
        for(int i=1;i<=n;i++)
        {
            st.insert(make_pair(c[i][n/2+1],make_pair(i,n/2+1)));
            st.insert(make_pair(c[n/2+1][i],make_pair(n/2+1,i)));
            st.insert(make_pair(c[i][n],make_pair(i,n)));
            st.insert(make_pair(c[n][i],make_pair(n,i)));
        }
        while(1)
        {
            auto pr=*st.begin();
            int i=pr.second.first;
            int j=pr.second.second;
            ll now=pr.first;
            st.erase(st.begin());
            if(vis[i][j]==1)
            {
                continue;
            }
            vis[i][j]=1;
            if(i<=n/2)
            {
                if(i==1||i==n/2)
                {
                    cout<<ans+now<<endl;
                    break;
                }
                add(st,i-1,j,now);
                add(st,i+1,j,now);
                if(j!=n)
                {
                    add(st,i,j+1,now);
                }
                if(j-1!=n/2)
                {
                    add(st,i,j-1,now);
                }
            }
            else
            {
                if(j==1||j==n/2)
                {
                    cout<<ans+now<<endl;
                    break;
                }
                add(st,i,j-1,now);
                add(st,i,j+1,now);
                if(i!=n)
                {
                    add(st,i+1,j,now);
                }
                if(i-1!=n/2)
                {
                    add(st,i-1,j,now);
                }
            }
        }
    }
    return 0;
}
/*
1000
4
0 0 0 0 1000    1000    1000    1000
0 0 0 0 1000    1       1       1
0 0 0 0 1       1       1000    1
0 0 0 0 1000    1000    1000    1
10000 10000 10000 10000 10 10 10 10
10000 10000 10000 10000 10 10 10 10
10000 10000 10000 10000 10 10 10 10
10000 10000 10000 10000 10 10 10 10
*/