#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;
pii trace[510][5010];
int d,s,visit[510][5010];

void out()
{
    vector<int> ans;
    int u=0,v=s;
    while (trace[u][v].se)
    {
        int x=trace[u][v].fi,y=trace[u][v].se;
        ans.pb(v-y);
        u=x;
        v=y;
    }
    cout<<v;
    for (int i=(int)ans.size()-1;i>=0;i--) cout<<ans[i];
}

void bfs()
{
    queue<pii> q;
    q.push(mp(0,0));
    while (!q.empty())
    {
        int u=q.front().fi,v=q.front().se;
        q.pop();
        for (int i=0;i<=9;i++)
        {
            int x=(u*10+i)%d,y=v+i;
            if (y<=s && !visit[x][y])
            {
                trace[x][y]=mp(u,v);
                visit[x][y]=1;
                q.push(mp(x,y));
            }
        }
        if (u==0 && v==s)
        {
            out();
            return;
        }
    }
    cout<<-1;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>d>>s;
    bfs();
    return 0;
}