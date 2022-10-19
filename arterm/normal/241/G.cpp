#include <iostream>

#define INF 990000
#define d 333

using namespace std;

int main()
{
    long r;
    cout<<2+d<<"\n";
    cout<<0<<" "<<INF<<"\n";
    r=100000;
    for (long i=d; i>0; --i){
        cout<<r<<" "<<5*i<<"\n";
        r+=(10*i);
    }
    cout<<INF<<" "<<INF<<"\n";
    return 0;
}