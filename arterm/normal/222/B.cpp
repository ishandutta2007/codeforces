#include <iostream>

#define M 1010

using namespace std;

long n,m,k,a[M][M],c[M],r[M];

void read(void){
    cin>>n>>m>>k;
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=m; ++j)
    cin>>a[i][j];

    for (long i=1; i<=n; ++i)
    r[i]=i;
    for (long j=1; j<=m; ++j)
    c[j]=j;
}


int main()
{
    char ch;
    long x,y;
    read();
    for (long i=0; i<k; ++i){
        cin>>ch>>x>>y;
        if (ch=='c')
        swap(c[x],c[y]);
        if (ch=='r')
        swap(r[x],r[y]);
        if (ch=='g')
        cout<<a[r[x]][c[y]]<<"\n";
    }
    return 0;
}