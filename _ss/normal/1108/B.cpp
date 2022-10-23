#include <iostream>

using namespace std;
int n,a[129],x=0,b[129],c[10001];
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        x=max(a[i],x);
    }
    for (int i=1;i<=n;i++)
        if (x%a[i]==0 && c[a[i]]==0)
        {
            c[a[i]]=1;
            b[i]=1;
        }
    int y=0;
    for (int i=1;i<=n;i++)
        if (b[i]==0) y=max(y,a[i]);
    cout<<x<<" "<<y;
    return 0;
}