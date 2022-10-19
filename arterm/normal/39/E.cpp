#include <iostream>


#define long long long
#define A 100100
#define B 40

using namespace std;

long n;
bool h[A][B],u[A][B];

bool big(long a, long b){
    long ans=1;
    for (long i=0; i<b; ++i){
        ans*=a;
        if (ans>=n)
        return 1;
    }
    return 0;
}

bool win(long a, long b){

    if (b==1 && a>A-10)
    return (n-a)%2==0;

    if (u[a][b])
    return h[a][b];

    u[a][b]=1;
    if (big(a,b))
    return h[a][b]=1;

    if (!win(a+1,b) || !win(a, b+1))
    return h[a][b]=1;

    return h[a][b]=0;
}

bool miss(long a, long b){
    for (long i=b; i<B; ++i)
    if (!win(a+1,i)){
        if ((i-b)%2==0)
        cout<<"Masha";
        else
        cout<<"Stas";
        return 0;
    }

    cout<<"Missing";
    return 1;

}

int main()
{
    long a,b;
    cin>>a>>b>>n;

    if ((a>1))
    if (win(a,b))
    cout<<"Masha";
    else
    cout<<"Stas";

    if (a==1)
    miss(a,b);

    return 0;
}