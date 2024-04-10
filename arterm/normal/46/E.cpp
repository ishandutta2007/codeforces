#include <iostream>

#define M 1777
#define long long long

using namespace std;


long n,m,a[M][M],l[M],b[M];

void read(void){
    cin>>n>>m;
    for (long i=1; i<=n; ++i)
    for (long j=1; j<=m; ++j){
        cin>>a[i][j];
        a[i][j]+=a[i][j-1];
    }
}

void din(void){
    b[m]=a[1][m];
    for (long i=m-1; i>=1; --i)
    b[i]=max(b[i+1],a[1][i]);
    for (long i=2; i<=n; ++i)
    if (i%2==0){
        l[1]=a[i][1]+b[2];
        for (long j=2; j<m; ++j)
        l[j]=max((a[i][j]+b[j+1]),l[j-1]);
    }
    else{
        b[m]=a[i][m]+l[m-1];
        for (long j=m-1; j>1; --j)
        b[j]=max(b[j+1],(a[i][j]+l[j-1]));
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    din();
    if (n%2==0)
    cout<<l[m-1];
    else
    cout<<b[2];
    return 0;
}