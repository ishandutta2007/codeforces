#include <iostream>

#define M 499

using namespace std;


long n,k,c;
bool b[M];

void read(void){
    cin>>n>>k;
    cin>>c;
    for (long i=0,x; i<c; ++i)
    cin>>x,b[x]=1;

}

void solve(void){
    long l=0,r=1;
    while (r<=n){
        if (b[r])
        l=r;
        if(r-l>=k)
        l=r,c++;
        r++;
    }

    cout<<c;

}

int main()
{
    read();
    solve();
    return 0;
}