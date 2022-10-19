#include <iostream>

#define M 1010

using namespace std;

int n,m,a[M][M],t[M],h,c;
bool b[M*M];

void read(void){
    cin>>n>>m;
    for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j)
    cin>>a[i][j];
    
    h=m*m;
    
}

bool isRectangle(int k){
    for (int i=0; i<h; ++i)
    b[i]=0;
    
    for (int i=0; i<n; ++i){
        c=0;
        for (int j=0; j<m; ++j)
        if (a[i][j]>=k)
        t[c++]=j;
        for (int j=0; j<c; ++j)
        for (int f=j+1; f<c; ++f){
            int x=t[j]+m*t[f];
            if (b[x])
            return 1;
            b[x]=1;
        }
    }
    return 0;
}

void bin(void){
    int l=0,r=1000000000,m;
    while (l<r){
        m=(l+r)/2;
        if (isRectangle(m+1))
        l=m+1;
        else
        r=m;
    }
    cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    bin();
    return 0;
}