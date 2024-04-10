#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=int(3e5)+1;
long long a[maxn],n;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long t=0;
    for (int i=1;i<=n/2;i++) t=t+(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    cout<<t;
    return 0;
}