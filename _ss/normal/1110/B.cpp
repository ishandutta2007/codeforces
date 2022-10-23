#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=int(1e5)+1;
int n,a[maxn],k,m,b[maxn];

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int kq=a[n]-a[1]+1;
    for (int i=1;i<n;i++) b[i]=a[i+1]-a[i]-1;
    sort(b+1,b+n);
    n--;
    k--;
    for (int i=n;i>=n-k+1;i--) kq=kq-b[i];
    cout<<kq;
    return 0;
}