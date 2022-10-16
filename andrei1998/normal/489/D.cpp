#include <iostream>
#include <bitset>

using namespace std;

bitset<3005> mat[3005];
int mat2[3005][3005];

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0,m=0;
    cin>>n>>m;

    int a,b;
    while(m--){
        cin>>a>>b;

        mat[a][b]=1;
    }

    long long int ans=0;

    int i,j,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(mat[i][j])
                for(k=1;k<=n;k++)
                    if(mat[j][k] && k!=i)
                        mat2[i][k]++;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            ans+=((mat2[i][j]*(mat2[i][j]-1ll))>>1);

    cout<<ans<<'\n';
    return 0;
}