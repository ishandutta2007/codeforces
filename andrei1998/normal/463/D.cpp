#include <iostream>
#include <bitset>

using namespace std;

int p[6][1005];
int n,k;

bitset<1005> mat[1005];

inline bool comp(int i,int j){
    for(int l=1;l<=k;l++)
        if(p[l][i]>p[l][j])
            return 0;
    return 1;
}

int din[1005];
bitset<1005> viz;

void dfs(int nod){
    din[nod]=1;
    for(int i=1;i<=n;i++)
        if(mat[nod][i]){
            if(!viz[i]){
                viz[i]=1;
                dfs(i);
            }

            if(din[i]+1>din[nod])
                din[nod]=din[i]+1;
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;

    int x;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            p[i][x]=j;
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                mat[i][j]=comp(i,j);

    for(int i=1;i<=n;i++)
        if(!viz[i]){
            viz[i]=1;
            dfs(i);
        }

    int ans=0;
    for(int i=1;i<=n;i++)
        if(din[i]>ans)
            ans=din[i];

    cout<<ans<<'\n';
    return 0;
}