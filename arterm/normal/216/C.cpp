#include <iostream>

using namespace std;

int main()
{
    long n,m,k;
    cin>>n>>m>>k;
    if (n>=m+2){
        cout<<2*k<<endl;
        for (long i=1; i<=k; ++i)
        cout<<1<<" ";
        for (long i=1; i<=k; ++i)
        cout<<n<<" ";
        return 0;
    }

    if (n==m+1 && k>1){
        cout<<2*k<<endl;
        for (long i=1; i<=k; ++i)
        cout<<1<<" ";
        cout<<n<<" ";
        for (long i=2; i<=k; ++i)
        cout<<n+1<<" ";
        return 0;
    }

    if (n==m+1 && k==1){
        cout<<3<<endl;
        cout<<1<<" ";
        cout<<n<<" ";
        cout<<n+1<<" ";
        return 0;
    }

    if (n==m && k>1){
        cout<<2*k+1<<endl;
        for (long i=1; i<=k; ++i)
        cout<<1<<" ";
        cout<<n<<" ";
        for (long i=2; i<=k; ++i)
        cout<<n+1<<" ";
        cout<<n+2<<" ";
        return 0;
    }

    if (n==2 && n==m && k==1){
        cout<<4<<"\n";
        cout<<1<<" ";
        cout<<2<<" ";
        cout<<3<<" ";
        cout<<4<<" ";
        return 0;
    }

    if (n==m && k==1 && n!=2){
        cout<<3<<endl;
        cout<<1<<" ";
        cout<<n<<" ";
        cout<<2*n-1<<" ";
        return 0;
    }


    return 0;
}