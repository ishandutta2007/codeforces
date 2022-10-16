#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> graf[105];
int x[105][105];
bitset<105> cores;
bitset<105> mems;
int cand[105];

int main()
{
    int n,m,k,i,j;
    cin>>n>>m>>k;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>x[i][j];

    for(i=1;i<=m;i++)
    {
        for(j=0;j<=k;j++)
            graf[j].clear();
        for(j=1;j<=n;j++)
            if(!cores[j])
                graf[x[j][i]].push_back(j);

        for(j=1;j<=k;j++)
            if(mems[j] || graf[j].size()>1)
            {
                mems[j]=1;

                for(vector<int>::iterator it=graf[j].begin();it!=graf[j].end();it++)
                    cores[*it]=1,cand[*it]=i;
            }
    }

    for(i=1;i<=n;i++)
        cout<<cand[i]<<'\n';

    return 0;
}