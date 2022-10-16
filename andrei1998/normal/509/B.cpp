#include <bits/stdc++.h>

using namespace std;

int v[105];
int mat[105][105];

int main()
{
    int n,k;
    cin>>n>>k;

    int minim=1000;
    int maxim=-1;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        minim=min(minim,v[i]);
        maxim=max(maxim,v[i]);
    }

    if(maxim-minim>k) {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=minim;j++)
            mat[i][j]=1;
        for(int j=minim+1;j<=v[i];j++)
            mat[i][j]=j-minim;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=v[i];j++)
            cout<<mat[i][j]<<' ';
        cout<<'\n';
    }

    return 0;
}