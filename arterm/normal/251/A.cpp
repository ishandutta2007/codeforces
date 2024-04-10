#include <iostream>

#define M 100100
#define long long long

using namespace std;

long n,x[M],d,s=0,k;

void read(void){
    cin>>n>>d;
    for (long i=0; i<n; ++i)
    cin>>x[i];
    long l=0,r=0;
    while (l<n){
        while (r<n && x[r]-x[l]<=d)
        ++r;
        k=r-l-1;
        if (k>=0)
        s=s+(k)*(k-1)/2;
        l++;
    }
    cout<<s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    return 0;
}