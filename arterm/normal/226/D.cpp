#include <iostream>

#define M 121

using namespace std;

long n,m,a[M][M],r[M],c[M],sr=0,sc=0;
bool ur[M],uc[M];

void read(void){
    cin>>n>>m;
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=m; ++j){
        cin>>a[i][j];
        r[i]+=a[i][j];
        c[j]+=a[i][j];
    }
}

void greed(void){
    bool fl=0;
    while (!fl){
        fl=1;
        for (long i=1; i<=n; ++i)
        if (r[i]<0){
            fl=0;
            ur[i]=!ur[i];
            r[i]=-r[i];
            for (long j=1; j<=m; ++j){
                a[i][j]*=-1;
                c[j]+=(2*a[i][j]);
            }
        }
        for (long j=1; j<=m; ++j)
        if (c[j]<0){
            fl=0;
            uc[j]=!uc[j];
            c[j]*=-1;
            for (long i=1; i<=n; ++i){
                a[i][j]*=-1;
                r[i]+=(2*a[i][j]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    greed();
    for (long i=1; i<=n; ++i)
    if (ur[i])
    ++sr;
    cout<<sr<<" ";
    for (long i=1; i<=n; ++i)
    if (ur[i])
    cout<<i<<" ";
    cout<<"\n";
    for (long i=1; i<=m; ++i)
    if (uc[i])
    ++sc;
    cout<<sc<<" ";
    for (long i=1; i<=m; ++i)
    if (uc[i])
    cout<<i<<" ";
    cout<<"\n";

    return 0;
}