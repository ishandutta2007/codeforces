#include <iostream>

using namespace std;
const int maxn=int(5e3)+1;
int n,a[maxn],b[maxn],l[maxn][maxn];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int d=1;
    b[1]=a[1];
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1])
        {
            d++;
            b[d]=a[i];
        }
    int m=0;
    for (int i=1;i<=d;i++)
        for (int j=d;j>=1;j--)
        {
        if (b[i]==b[j]) l[i][j]=l[i-1][j+1]+1;
        else l[i][j]=max(l[i-1][j],l[i][j+1]);
        m=max(m,l[i][j]);
        }
    cout<<d-m/2-1;
    //for (int i=1;i<=d;i++) cout<<b[i]<<" ";
    return 0;
}