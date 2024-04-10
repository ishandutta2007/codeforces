#include <iostream>
#include <string>

using namespace std;

string s;
long n;


bool good(long k){
    for (long i=0; i+k<=n; ++i)
    for (long j=i+1; j+k<=n; ++j)
    if (s.substr(i,k)==s.substr(j,k))
    return 1;
    return 0;
}

void solve(void){

    cin>>s;
    n=s.length();

    long l=0,r=n,m;

    while (l<r){
        m=(l+r+2)>>1;
        good(m) ? l=m:r=m-1;
    }

    cout<<l;

}

int main()
{
    solve();
    return 0;
}