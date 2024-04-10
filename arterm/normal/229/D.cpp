#include <iostream>

#define M 5555

using namespace std;

long n,h[M],p[M],w[M];

void read(void){
    cin>>n;
    for (long i=1; i<=n; ++i)
    cin>>h[i];
}

void din(void){
    long s;
    w[1]=h[1];
    p[1]=0;
    h[0]=0;
    p[0]=0;
    w[0]=0;
    for (long i=2,j; i<=n; ++i){
        p[i]=1000000;
        s=h[i];
        j=i-1;
        for(;j>=0;--j){
            if (s>=w[j])
            if (p[i]>i-j-1+p[j]){
                w[i]=s;
                p[i]=i-j-1+p[j];
            }
            s+=h[j];
        }
        /*while (s<w[j] && j>0)
        s+=h[j--];*/
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    din();
    cout<<p[n];
    return 0;
}