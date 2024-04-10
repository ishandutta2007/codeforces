#include <iostream>

#define long long long

#define M 40

using namespace std;

long n,h,d[M][M];

void solve(void){
    long s=0;

    cin>>n>>h;
    d[1][1]=1;
    d[0][0]=1;
    for (long t=1; t<=n; ++t)
    for (long i=2; i<=n; ++i)
    for (long j=1; j<=i; ++j){
        for (long k=t; k>=1; --k)
        d[i][t]=d[i][t]+d[j-1][t-1]*d[i-j][k-1];
        for (long k=t-1; k>=1; --k)
        d[i][t]=d[i][t]+d[j-1][k-1]*d[i-j][t-1];
    }




    for (long i=h; i<=n; ++i)
    s+=d[n][i];
    cout<<s;

}


int main()
{
    solve();
    return 0;
}