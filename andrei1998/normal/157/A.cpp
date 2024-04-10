#include <iostream>

using namespace std;

int mat[35][35];
int lin[35];
int col[35];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>mat[i][j];
            lin[i]+=mat[i][j];
            col[j]+=mat[i][j];
        }

    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(col[j]>lin[i])
                ans++;

    cout<<ans<<'\n';
    return 0;
}