#include <iostream>

#define long long long

using namespace std;

long a[121][121],b=0,k;

void greed(void){
    long n=3,t=2,bo=b;
    while (n*(n-1)*(n-2)/6<=k)
    ++n;
    for (long i=1; i<n; ++i)
    for (long j=1; j<n; ++j)
    if (i!=j)
    a[b+i][b+j]=1;
    else
    a[b+i][b+j]=0;
    k=k-((n-1)*(n-2)*(n-3)/6);


    while(k>0){
        t=2;
        while (t*(t-1)/2<=k)
        ++t;


        for (long i=1; i<t; ++i){
            a[b+n][b+i]=1;
            a[b+i][b+n]=1;
        }


        k=k-((t-2)*(t-1)/2);
        n++;
    }
    b=b+n-1;
}

int main()
{
    long n=3,t=2;
    cin>>k;

    greed();


    cout<<b<<endl;
    n=b;
    for (long i=1; i<=n; ++i){
        for (long j=1; j<=n; ++j)
        cout<<a[i][j];
        cout<<endl;
    }

    return 0;
}