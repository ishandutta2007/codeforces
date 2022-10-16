#include <iostream>

#define mod 1000000007
using namespace std;

int din[5005][5005];

int main()
{
    int n,a,b,k;
    cin>>n>>a>>b>>k;

    if(a>b){
        a=n-a+1;
        b=n-b+1;
    }

    b--;

    int i,j;
    for(i=a;i<=b;i++)
        din[0][i]=1;

    for(i=1;i<=k;i++)
        for(j=1;j<=b;j++){
            din[i][j]=(din[i][j-1]+(mod-din[i-1][j]))%mod+(din[i-1][(b+j)>>1]+din[i-1][j-1])%mod;
            if(din[i][j]>=mod)
                din[i][j]-=mod;
        }

    cout<<din[k][b]<<'\n';
    return 0;
}