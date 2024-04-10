#include <iostream>

#define mod 1000000007
using namespace std;

int din[2005][2005];

int main()
{
    int n,k;
    cin>>k>>n;

    for(int i=1;i<=k;i++)
        din[1][i]=1;

    for(int i=1;i<n;i++)
        for(int j=1;j<=k;j++)
            for(int p=j;p<=k;p+=j){
                din[i+1][p]+=din[i][j];
                if(din[i+1][p]>=mod)
                    din[i+1][p]-=mod;
            }

    int sum=0;
    for(int i=1;i<=k;i++){
        sum+=din[n][i];
        if(sum>=mod)
            sum-=mod;
    }
    cout<<sum<<'\n';

    return 0;
}