#include <iostream>
#include <algorithm>

#define M 1010

using namespace std;

long n,m,p[M];
double a[M][M],b[M][M];

void swp(long x, long y){
    for (long i=1; i<=n; ++i){
        b[i][y]=b[i][x]=(a[i][x]+a[i][y])/2;
        b[y][i]=b[x][i]=(a[x][i]+a[y][i])/2;
    }
    b[x][y]=b[y][x]=0.5;
    for (long i=1; i<=n; ++i)
    if (i!=x && i!=y){
        a[i][y]=a[i][x]=b[i][x];
        a[y][i]=a[x][i]=b[x][i];
    }
    a[x][y]=a[y][x]=0.5;
}

void read(void){
    cin>>n>>m;
    for (long i=1; i<=n; ++i)
    cin>>p[i];
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=n; ++j)
    if (p[i]>p[j])
    a[i][j]=1;
    else
    a[i][j]=0;

    for (long x,y,i=0; i<m; ++i){
        cin>>x>>y;
        swp(x,y);
    }

    double s=0;

    for (long i=1; i<=n; ++i)
    for (long j=i+1; j<=n; ++j)
    s+=a[i][j];

    cout.precision(9);
    cout<<fixed<<s<<"\n";

}


int main()
{
    ios_base::sync_with_stdio(0);
    read();
    return 0;
}