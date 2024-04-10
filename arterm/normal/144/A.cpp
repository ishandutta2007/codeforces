#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    long n, a, mn,mx,lmn, lmx;
    cin>>n;
    cin>>mn;
    mx=mn;
    lmx=0;
    lmn=0;
    for (long i=1; i<n; ++i){
        cin>>a;
        if (a<=mn){
                  mn=a;
                  lmn=i;
                  }
        if (a>mx){
                  mx=a;
                  lmx=i;
                  }
        }
    if (lmx<lmn)
    cout<<lmx+n-lmn-1;
    else
    cout<<lmx+n-lmn-2;
    //system("PAUSE");
    return 0;
}