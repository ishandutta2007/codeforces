#include <iostream>
#include <cmath>

#define NMAX 2005
#define mod 1000000007
using namespace std;

int v[NMAX];
int din[NMAX][NMAX];

int main()
{
    int n=0,h;
    cin>>n>>h;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=1;i<=n;i++){
        v[i]=h-v[i];

        if(v[i]<0){
            cout<<"0\n";
            return 0;
        }
    }

    for(int i=n;i>=1;i--)
        v[i]-=v[i-1];

    din[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            if(v[i+1]==0){
                din[i+1][j]+=din[i][j];
                if(din[i+1][j]>=mod)
                    din[i+1][j]-=mod;

                if(j>=1){
                    din[i+1][j]=(din[i+1][j]+(1ll*j*din[i][j])%mod);
                    if(din[i+1][j]>=mod)
                        din[i+1][j]-=mod;
                }
            }
            else if(v[i+1]==1){
                din[i+1][j+1]+=din[i][j];
                if(din[i+1][j+1]>=mod)
                    din[i+1][j+1]-=mod;
            }
            else if(v[i+1]==-1){
                if(j>=1){
                    din[i+1][j-1]=(din[i+1][j-1]+(1ll*j*din[i][j])%mod);

                    if(din[i+1][j-1]>=mod)
                        din[i+1][j-1]-=mod;
                }
            }

    int ans=0;
    for(int i=0;i<=1;i++){
        ans+=din[n][i];
        if(ans>=mod)
            ans-=mod;
    }

    cout<<ans<<'\n';
    return 0;
}