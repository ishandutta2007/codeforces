#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

int p[5005];
lint s_part[5005];

lint din[5005][5005];

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0,m=0,k=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        s_part[i]=s_part[i-1]+p[i];
    }

    int i,j;

    for(i=0;i<=n;i++)
        for(j=0;j<=k;j++){
            din[i+1][j]=max(din[i+1][j],din[i][j]);
            if(i+m<=n)
                din[i+m][j+1]=max(din[i+m][j+1],din[i][j]+s_part[i+m]-s_part[i]);
        }

    cout<<din[n][k]<<endl;
    return 0;
}