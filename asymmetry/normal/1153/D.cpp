#include <bits/stdc++.h>

using namespace std;

int n, a, k, g, xd;
int r[300101]; //rodzaj
int o[300101]; //ojciec
int s[300101]; //stopie
int z[300101];
int p[200101];
vector <pair <int, int> > v[300101];
queue <int> q;

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &r[i]);
    }
    o[1]=0;
    for(int i=2; i<=n; ++i)
    {
        scanf("%d", &a);
        o[i]=a;
        ++s[a];
    }
    for(int i=1; i<=n; ++i)
    {
        if(!s[i])
        {
            ++k;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        a=q.front();
        g=1000000000;
        xd=0;
        q.pop();
        if(!v[a].size())
        {
            v[o[a]].push_back({k, 1});
            p[a]=1;
        }
        else
        {
            sort(v[a].begin(), v[a].end());
            if(r[a])
            {
                g=v[a][v[a].size()-1].first;
                xd=v[a][v[a].size()-1].second;
            }
            else
            {
                for(int i=0; i<v[a].size(); ++i)
                {
                    g=min(g, v[a][i].first-xd);
                    xd+=v[a][i].second;
                }
            }
            v[o[a]].push_back({g, xd});
            p[o[a]]+=p[a];
        }
        --s[o[a]];
        if(!s[o[a]])
        {
            q.push(o[a]);
        }
    }
    /*for(int i=0; i<=n; ++i)
    {
        printf("%d: ", i);
        for(int j=0; j<v[i].size(); ++j)
        {
            printf("(%d %d) ", v[i][j].first, v[i][j].second);
        }
        printf("\n");
    }*/
    printf("%d", v[0][0]);
    return 0;
}