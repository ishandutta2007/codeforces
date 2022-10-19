#include <iostream>

#define N 1001

using namespace std;

int f[N][N], c[N][N];

int main()
{
    long n,m,x,y,u=0,v=0,u1,u2;
    for (long i=0; i<N; ++i)
    for (long j=0; j<N; ++j){
        f[i][j]=0;
        c[i][j]=0;
    }
    cin>>n>>m;
    for (long i=0; i<n; ++i){
        cin>>x>>y;
        f[y][x]++;
    }
    for (long j=0; j<m; ++j){
        cin>>x>>y;
        c[y][x]++;
    }
    for (long i=1; i<N; ++i){
        u1=0;
        u2=0;
        for (long j=1; j<N; ++j){
            v+=min(f[i][j],c[i][j]);
            u1+=f[i][j];
            u2+=c[i][j];
        }
        u+=min(u1,u2);
    }
    cout<<u<<" "<<v;
    return 0;
}