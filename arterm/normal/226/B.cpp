#include <iostream>
#include <algorithm>

#define M 100100
#define long long long

using namespace std;

long n,a[M],q,k,r=0,h[M];
bool u[M];

void read(void){
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i];
    sort(a,a+n);
    for (long i=n-1; i>=0; --i)
    r+=(a[i]*(n-1-i));
    for (long i=1; i<n; ++i)
    a[i]+=a[i-1];

}

void ans(void){
    if(u[k]){
        cout<<h[k]<<"\n";
        return;
    }

    long l=n-1,t=1,s=0,b=0;
    while (l>=0){
        if (l>=t)
        s=s+(a[l]-a[l-t])*b;
        else
        s=s+a[l]*b;
        l=l-t;
        b++;
        t*=k;
    }
    h[k]=s;
    u[k]=1;
    cout<<s<<"\n";
}


int main()
{
    read();
    cin>>q;
    for (long i=0; i<q; ++i){
        cin>>k;
        if (k>1)
        ans();
        else
        cout<<r<<"\n";
    }
    return 0;
}