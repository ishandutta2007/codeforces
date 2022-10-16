#include <iostream>
#include <algorithm>

using namespace std;

bool mat[305][305];
int perm[305];

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>perm[i];

    int i,j;

    char x;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            cin>>x;
            mat[i][j]=((bool)(x-'0'));
        }


    for(int i=1;i<=n;i++)
        mat[i][i]=1;

    int k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(mat[i][k] && mat[k][j])
                    mat[i][j]=1;

    int minim;
    int poz;

    for(i=1;i<=n;i++) {
        minim=perm[i];
        poz=i;

        for(j=i+1;j<=n;j++)
            if(mat[i][j])
                if(perm[j]<minim){
                    minim=perm[j];
                    poz=j;
                }
        swap(perm[i],perm[poz]);
    }

    for(i=1;i<=n;i++)
        cout<<perm[i]<<' ';
    cout<<endl;

    return 0;
}