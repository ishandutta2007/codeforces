#include <iostream>

#define M 307
#define long long long

using namespace std;

long n,k,d[M][M],s=0;

void read(void){
    cin>>n;
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=n; ++j)
    cin>>d[i][j],s+=d[i][j];
}

void solve(void){
    cin>>k;
    for (long a,b,c;k>0;k--){
        cin>>a>>b>>c;
        for (long i=1; i<=n; ++i)
        for (long j=1; j<=n; ++j){
            if (d[i][j]>d[i][a]+c+d[b][j]){
                s-=d[i][j];
                d[i][j]=d[i][a]+c+d[b][j];
                s+=d[i][j];
            }
            if (d[i][j]>d[i][b]+c+d[a][j]){
                s-=d[i][j];
                d[i][j]=d[i][b]+c+d[a][j];
                s+=d[i][j];
            }
        }


        cout<<s/2<<" ";
    }
}

int main()
{
    read();
    solve();
    return 0;
}