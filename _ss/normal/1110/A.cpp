#include <iostream>

using namespace std;
const int maxn=int(1e5)+1;
int k,a[maxn],b;
int main()
{
    int kq=0;
    cin>>b>>k;
    for (int i=1;i<=k;i++) cin>>a[i];
    for (int i=1;i<k;i++) kq=(kq+a[i]*b)%2;
    kq=(kq+a[k])%2;
    if (kq==0) cout<<"even"; else cout<<"odd";
    return 0;
}