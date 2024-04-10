#include <iostream>
#include <vector>

using namespace std;

int n,m;
char mat[1005][1005];

vector<char> curent[1005];
int tip[1005];
int nou_tip[1005];

void add(int col){
    for(int i=1;i<=n;i++)
        curent[i].push_back(mat[i][col]);

    for(int i=1;i<=n;i++)
        tip[i]=500*tip[i]+curent[i].back();

    int poz=1;
    nou_tip[1]=1;

    for(int i=2;i<=n;i++)
        if(tip[i]!=tip[i-1])
            nou_tip[i]=++poz;
        else
            nou_tip[i]=poz;

    for(int i=1;i<=n;i++)
        tip[i]=nou_tip[i];
}

bool ok(int col){
    for(int i=2;i<=n;i++)
        if(tip[i]==tip[i-1])
            if(mat[i][col]<mat[i-1][col])
                return 0;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>mat[i][j];

    for(i=1;i<=n;i++)
        curent[i].push_back('a'-1);

    int ans=m;
    for(j=1;j<=m;j++)
        if(ok(j)){
            add(j);
            ans--;
        }

    cout<<ans<<'\n';

    return 0;
}