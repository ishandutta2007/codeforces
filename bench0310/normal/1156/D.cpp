#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<array<int,2>> v[N];
ll res=0;

void ini(array<array<ll,2>,2> &a)
{
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j]=0;
}

array<array<ll,2>,2> dfs(int a,int p=-1)
{
    array<array<ll,2>,2> now;
    ini(now);
    for(auto [to,c]:v[a])
    {
        if(to==p) continue;
        array<array<ll,2>,2> tmp=dfs(to,a);
        array<array<ll,2>,2> x;
        ini(x);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(c==i) x[i][j]+=tmp[i][j];
                else if(i==j) x[c][i]+=tmp[i][j];
            }
        }
        x[c][c]++;
        for(int o=0;o<2;o++)
        {
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<2;j++)
                {
                    for(int k=0;k<2;k++)
                    {
                        int cnt=(1+(k!=j)+(j!=o)+(o!=i));
                        if(cnt==1) res+=(2*now[o][i]*x[j][k]);
                        else if(cnt==2) res+=(now[o][i]*x[j][k]);
                    }
                }
            }
        }
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) now[i][j]+=x[i][j];
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(i==j) res+=(2*now[i][j]);
            else res+=now[i][j];
        }
    }
    return now;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(1);
    cout << res << "\n";
    return 0;
}