#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define M 100
#define INF 2000000000000ll
#define long long long

using namespace std;

long k,n,m,a[M],b[M];

struct matrix{
    long a[M][M];
    matrix(){
        for (int i=0; i<M; ++i)
            for (int j=0; j<M; ++j)
                a[i][j]=(i==j)?0:INF;
    }
    void inf(){
        for (int i=0; i<M; ++i)
            for (int j=0; j<M; ++j)
                a[i][j]=INF;
    }
} ans,p;

matrix operator *(const matrix &a, const matrix &b){
    matrix c;
    c.inf();

    for (int i=0; i<k; ++i)
        for (int j=0; j<k; ++j)
            for (int t=0; t<k; ++t)
                c.a[i][j]=min(c.a[i][j],(a.a[i][t]+b.a[t][j]));
    return c;
}

void read(void){
    cin>>n>>m;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    for (int j=0; j<n; ++j)
        cin>>b[j];
}

void make(void){
    matrix t;
    k=2*n+1;
    for (int r=0; r<n; ++r){
        t.inf();
        for (int i=0; i<k; ++i)
            t.a[i][i+1]=a[r];
        for (int i=1; i<k; ++i)
            t.a[i][i-1]=b[r];
        p=p*t;
    }

    while (m){
        if (m&1)
            ans=ans*p;
        p=p*p;
        m>>=1;
    }
    cout<<ans.a[0][0]<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    read();
    make();
    return 0;
}