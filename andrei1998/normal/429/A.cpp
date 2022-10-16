#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define NMAX 100005
bitset<NMAX> viz;
vector<int> graf[NMAX];
vector<int> ans;

int init[NMAX];
int goal[NMAX];
int par[NMAX];
int impar[NMAX];
int n;

void dfs(int nod)
{
    if((par[nod]^init[nod])!=goal[nod])
    {
        par[nod]^=1;
        ans.push_back(nod);
    }

    vector<int>::iterator it;
    for(it=graf[nod].begin();it!=graf[nod].end();it++)
        if(!viz[*it])
        {
            viz[*it]=1;
            par[*it]=impar[nod];
            impar[*it]=par[nod];
            dfs(*it);
        }
}

int main()
{
    cin>>n;

    int i,a,b;
    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    for(i=1;i<=n;i++)
        cin>>init[i];

    for(i=1;i<=n;i++)
        cin>>goal[i];

    viz[1]=1;
    dfs(1);

    cout<<ans.size()<<'\n';

    vector<int>::iterator it;
    for(it=ans.begin();it!=ans.end();it++)
        cout<<*it<<'\n';

    return 0;
}