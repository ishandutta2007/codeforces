#include <iostream>

using namespace std;

inline bool gcd(int a,int b){
    int r=a%b;

    while(r){
        a=b;
        b=r;
        r=a%b;
    }

    return ((bool)(b==1));
}

inline bool ok(int a,int b,int c,int d){
    return (gcd(a,b) && gcd(a,c) && gcd(a,d));
}

int main()
{
    /*for(int i=1;i<=100;i+=2)
        if(ok(i,i+2,i+4,i+3) || ok(i,i+2,i+4,i+1))
            cout<<i<<' '<<endl;*/

    int n,k;
    cin>>n>>k;

    cout<<(6*n-1)*k<<'\n';

    for(int i=1;i<=n;i++)
        if(ok((6*i-5),(6*i-3),(6*i-1),6*i-2))
            cout<<(6*i-5)*k<<' '<<(6*i-3)*k<<' '<<(6*i-1)*k<<' '<<(6*i-2)*k<<'\n';
        else
            cout<<(6*i-5)*k<<' '<<(6*i-3)*k<<' '<<(6*i-1)*k<<' '<<(6*i-4)*k<<'\n';

    return 0;
}