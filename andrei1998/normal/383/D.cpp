#include <iostream>

#define mod 1000000007
using namespace std;

int n;
int v[1005];

int din[1005][10005];

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    int ans=0,j;

    din[0][5000]=1;
    for(int i=0;i<n;i++){
        for(j=0;j<=10000;j++){
            if(j+v[i+1]<=10000){
                din[i+1][j+v[i+1]]+=din[i][j];

                if(din[i+1][j+v[i+1]]>=mod)
                    din[i+1][j+v[i+1]]-=mod;
            }

            if(j-v[i+1]>=0){
                din[i+1][j-v[i+1]]+=din[i][j];

                if(din[i+1][j-v[i+1]]>=mod)
                    din[i+1][j-v[i+1]]-=mod;
            }
        }

        ans+=din[i+1][5000];

        din[i+1][5000]++;
        if(din[i+1][5000]>=mod)
            din[i+1][5000]-=mod;

        if(ans>=mod)
            ans-=mod;
    }

    cout<<ans<<'\n';
    return 0;
}