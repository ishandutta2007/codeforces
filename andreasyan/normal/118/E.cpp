#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;
struct ban
{
    int x,i;
};

int n,m;
vector<ban> a[N];

bool s[N*3];
vector<pair<int,int> > ans;

int t;
int tin[N],fup[N];
bool c[N];
void dfs(int x,int p)
{
    c[x]=true;
    fup[x]=tin[x]=t++;
    for(int i=0;i<a[x].size();++i)
    {
        ban hh=a[x][i];
        int h=hh.x;
        if(h==p)
            continue;
        if(c[h])
        {
            fup[x]=min(fup[x],tin[h]);
            if(!s[hh.i])
            {
                s[hh.i]=true;
                ans.push_back(m_p(x,h));
            }
        }
        else
        {
            dfs(h,x);
            if(fup[h]>tin[x])
            {
                cout<<0<<endl;
                exit(0);
            }
            fup[x]=min(fup[x],fup[h]);
            if(!s[hh.i])
            {
                s[hh.i]=true;
                ans.push_back(m_p(x,h));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        ban t;
        t.i=i;
        int x,y;
        cin>>x>>y;
        t.x=y;
        a[x].push_back(t);
        t.x=x;
        a[y].push_back(t);
    }
    dfs(1,-1);
    for(int i=0;i<m;++i)
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    return 0;
}