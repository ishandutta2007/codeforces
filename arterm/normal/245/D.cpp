#include <iostream>

#define M 107

using namespace std;

long n,b[M][M],a[M];

void read(void){
    cin>>n;
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=n; ++j)
    cin>>b[i][j];

}

void solve(void){
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=n; ++j)
    if (i!=j)
    a[i]|=b[i][j];

    for (long i=1; i<=n; ++i)
    cout<<a[i]<<" ";

}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    solve();
    return 0;
}