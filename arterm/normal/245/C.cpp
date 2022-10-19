#include <iostream>

using namespace std;

void sub(long &x){
    if (x>0)--x;
}

int main()
{
    long n,a[200],l,t=0,k;
    cin>>n;
    for (long i=1; i<=n; ++i)
    cin>>a[i];
    l=n;
    while (l>0){
        while (l>0 && a[l]==0)
        --l;
        if (l==0)
        break;

        if (l>1)
        k=l/2;
        else
        k=1;

        if (2*k+1>n){
            t=-1;
            break;
        }

        while (a[l]>0){
            sub(a[k]);
            sub(a[2*k]);
            sub(a[2*k+1]);
            t++;
        }

    }
    cout<<t;
    return 0;
}