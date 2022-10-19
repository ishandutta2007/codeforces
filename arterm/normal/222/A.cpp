#include <iostream>

using namespace std;

long n,k,a[100100];

int main()
{
    long b;
    cin>>n>>k;
    for (long i=1; i<=n ;++i)
    cin>>a[i];
    b=n;
    while (b>0 && a[n]==a[b])
    --b;
    b++;
    if (b>k){
        cout<<-1;
        return 0;
    }
    cout<<b-1;

    return 0;
}