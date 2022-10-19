#include <iostream>
#include <algorithm>

#define M 67
#define long long long

using namespace std;

long n,t,a[M][M],s[M],p[M],c[M][M],d[M];
bool pos=0;

int sum(int x){
    int s=0;
    while (x){
        s=s+(x&1);
        x>>=1;
    }
    return s;
}

void gen(int m){
    for (int j=1; j<=m; ++j)
    a[1][j]=0;
    a[1][m+1]=1;

    for (int i=2; i<=m+1; ++i)
    for (int j=1; j<=m+1; ++j)
    a[i][j]=a[i-1][j-1]^a[i-1][j+1];

    for (int i=1; i<=m+1; ++i)
    for (int j=1; j<=m+1; ++j)
    s[i]+=a[i][j];

    for (int i=1; i<=m+1; ++i)
    cout<<s[i]<<"\n";

    /*cout<<"1: ";
    for (int i=1; i<=m+1; ++i,cout<<"\n"<<i<<": ")
    for (int j=1; j<=m+1; ++j,cout<<" ")
    cout<<a[i][j];*/

}

void pre(void){
    p[0]=1;
    for (int i=1; i<M; ++i)
    p[i]=p[i-1]<<1;

    for (int i=0; i<M; ++i)
    c[i][0]=1;
    for (int i=1; i<M; ++i)
    for (int j=1; j<M; ++j)
    c[i][j]=c[i-1][j-1]+c[i-1][j];
}

void read(void){
    cin>>n>>t;
    for (int i=0; i<M; ++i)
    if (p[i]==t){
        t=i+1;
        pos=1;
        break;
    }
    n++;
}

void kill(void){
    long ans=0,s=0;
    for (int i=50; i>=0; --i){
        if ((p[i]&n)==0)
        continue;

        ans=ans+c[i][t-s];
        s++;
    }

    if (s==t)
    ans++;

    if (t==1)
    ans--;

    cout<<ans<<"\n";

}

int main(){
    pre();
    read();
    if (pos)
    kill();
    else
    cout<<"0\n";
}