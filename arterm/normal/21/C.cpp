#include <iostream>

#define M 100100
#define long long long

using namespace std;

long n,a[M],s=0,d=0,ans=0;
bool b[M];

void read(void){
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>a[i],s+=a[i];
}

void din(void){



    if (s%3!=0){
        cout<<0;
        return;
    }

    s=s/3;
    for (long i=n-1,p=0; i>0; --i){
        p+=a[i];
        if (p==s)
        b[i-1]=1,d++;
    }
    for (long i=0,p=0; i<n; ++i){
        p+=a[i];
        if (b[i])
        --d;
        if (p==s)
        ans+=d;
    }

    cout<<ans;
}

int main()
{
    read();
    din();
    return 0;
}